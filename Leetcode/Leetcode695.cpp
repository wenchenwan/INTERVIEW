/**
 * 695. 岛屿的最大面积
 * @file Leetcode695.cpp
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
using namespace std;
class Solution {
public:
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int MaxArea = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int area = 0;
                dfs(grid,visited,i,j,area);
                MaxArea = max(area,MaxArea);
            }
        }
        return MaxArea;
    }

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int col,int row,int& MaxArea){
        if(col>=grid.size() || row>=grid[0].size() || visited[col][row] || !grid[col][row]){
            return;
        }
        visited[col][row] = true;
        MaxArea += 1;
        for(int i=0;i<4;i++){
            dfs(grid,visited,col+direction[i][0],row+direction[i][1],MaxArea);
        }
    }

};