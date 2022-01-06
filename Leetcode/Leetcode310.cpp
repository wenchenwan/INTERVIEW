/**
 * 310. 最小高度树
 * 
 * @file Leetcode310.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream> 
#include<vector>
#include "queue"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> degree(n,0);

        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();++i){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            
        }
        queue<int> q;
        for(int i=0;i<n;++i){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            res.clear();
            while(size--){
                int cur = q.front();
                q.pop();
                res.push_back(cur);

                degree[cur]--;
                for(auto& i : mp[cur]){
                    degree[i]--;
                    if(degree[i] == 1){
                        q.push(i);
                    }
                }
            }
        }

        return res;

    }
};