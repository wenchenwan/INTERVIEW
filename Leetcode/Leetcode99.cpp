/**
 * 99. 恢复二叉搜索树
 * 
 * @file Leetcode99.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */


//解法1

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
class Solution {
public:
    TreeNode* t1 = nullptr;
    TreeNode* t2 = nullptr;
    TreeNode* pre = nullptr;
    void recoverTree(TreeNode* root) {
        
        dfs(root);
        
        int temp = t1->val;
        t1->val = t2->val;
        t2->val = temp;
        //swap(t1,t2);
    }

    void dfs(TreeNode* node){
        if(node==nullptr) return;
        dfs(node->left);

        if(pre == nullptr){
            pre = node;
        }else{
            if(pre->val > node->val){
                t2 = node;
                if(t1 == nullptr){
                    t1 = pre;
                }
            }

            pre = node;
        }
        dfs(node->right);
    }
    void swap(TreeNode* node1, TreeNode* node2){
        if(node1==nullptr || node2 == nullptr) return;
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};

// 解法2
class Solution {
public:
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        TreeNode* t1 = nullptr;
        TreeNode* t2 = nullptr;
        dfs(root,vec);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]->val > vec[i+1]->val){
                t1 = vec[i+1];
                if(t2 == nullptr) t2 = vec[i]; 
            }
        }
        swap(t1,t2);
    }

    void dfs(TreeNode* node,vector<TreeNode*>& vec){
        if(node==nullptr) return;
        dfs(node->left,vec);
        vec.push_back(node);
        dfs(node->right,vec);
    }
    void swap(TreeNode* node1, TreeNode* node2){
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};