/**
 * 547. 省份数量
 * 
 * @file Leetcode547.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream> 
#include<vector>
#include "queue"
#include "unordered_map"
using namespace std;


// 1、深度优先搜索
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        
        int n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                ++count;
            }
            
        }

        return count;
    }

    void dfs(vector<vector<int>>& isConnected,int i,vector<bool>& visited){
        visited[i] = true;
        for(int j=0;j<isConnected.size();++j){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(isConnected,j,visited);
            }
        }
    }
};


//2、广度优先搜索
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n,false);
        queue<int> que;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                que.push(i);
                while(!que.empty()){
                    int temp = que.front();
                    que.pop();
                    visited[temp] = true;
                    for(int k=0;k<n;++k){
                        if(isConnected[temp][k] == 1 && !visited[k]){
                            que.push(k);
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};


//2 利用并查集

class UnionFind{
public:
    int find(int x){
        int root = x;
        
        while(father[root] != -1){
            root = father[root];
        }
        
        while(x != root){
            int original_father = father[x];
            father[x] = root;
            x = original_father;
        }
        
        return root;
    }
    
    bool is_connected(int x,int y){
        return find(x) == find(y);
    }
    
    void merge(int x,int y){
        int root_x = find(x);
        int root_y = find(y);
        
        if(root_x != root_y){
            father[root_x] = root_y;
            num_of_sets--;
        }
    }
    
    void add(int x){
        if(!father.count(x)){
            father[x] = -1;
            num_of_sets++;
        }
    }
    
    int get_num_of_sets(){
        return num_of_sets;
    }
    
private:
    // 记录父节点
    unordered_map<int,int> father;
    // 记录集合数量
    int num_of_sets = 0;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        for(int i = 0;i < isConnected.size();i++){
            uf.add(i);
            for(int j = 0;j < i;j++){
                if(isConnected[i][j]){
                    uf.merge(i,j);
                }
            }
        }
        
        return uf.get_num_of_sets();
    }
};