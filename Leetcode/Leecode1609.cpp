/**
 * 
 * 1609. 奇偶树
 * 如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/even-odd-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * @brief 
 * 
 
 * @file Leecode1609.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<queue>
#include"queue"



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return false;
        queue<TreeNode*> que;
        
        que.push(root);
        int k = 0;
        
        while(!que.empty()){
            int pre = (k%2==0 ? -1 : INT_MAX);
            int n = que.size();
            for(int i=0;i<n;i++){
                TreeNode* node = que.front();
                que.pop();
                if(k%2 == 0 && node->val%2 == 0 || k%2 != 0 && node->val%2 != 0){
                    return false;
                }
                
                if(k%2 == 0 && pre < node->val||k%2 != 0 && pre > node->val){
                    pre = node->val;
                }else{
                    return false;
                }
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                
            }
            k++;
        }

        return true;
        
    }
};


//利用深度优先搜索实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int N = 1e5+7;
class Solution {
public:
    
    int dp[N];

    bool dfs(TreeNode* node,int p){
        if(p&1){//奇数
            if(node->val&1 || dp[p] <= node->val ) return false;
        }else{
            if(!(node->val&1) || dp[p] >= node->val ) return false;
        }
        dp[p] = node->val;
        if(node->left && !(dfs(node->left,p+1))) return false;
        if(node->right && !(dfs(node->right,p+1))) return false;

        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        for(int i=0;i<N-2;i = i+2) dp[i] = -1,dp[i+1] = INT_MAX;
        return dfs(root,0);
    }
};