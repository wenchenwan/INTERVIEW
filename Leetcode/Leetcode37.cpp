/**
 * 37. 解数独
 * 
 * @file Leetcode37.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "iostream"
#include "vector"

using namespace std;
class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }
};


class Solution {
public:
    bool col[9][9];
    bool row[9][9];
    bool block[3][3][9];
    bool valued = false;
    vector<pair<int,int>> space;


    void solveSudoku(vector<vector<char>>& board) {
        memset(col,false,sizeof(col));
        memset(row,false,sizeof(row));
        memset(block,false,sizeof(block));
        
        valued = false;

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] =='.'){
                    space.emplace_back(i,j);
                }else{
                    int digit = board[i][j] - '0' - 1;
                    row[i][digit] = col[j][digit] = block[i/3][j/3][digit] = true;
                }
            }
        }

        dfs(board,0);
    }

    void dfs(vector<vector<char>>& board,int pos){
        if(pos == space.size()){
            valued = true;
            return;
        }
        auto [i,j] = space[pos];
        for(int digit=0;digit<9 && !valued;++digit){
            if(!row[i][digit] || !col[j][digit] || !block[i/3][j/3][digit]){
                row[i][digit] = col[j][digit] = block[i/3][j/3][digit] = true;
                board[i][j] = digit+'0'+1;
                dfs(board,pos+1);
                
                row[i][digit] = col[j][digit] = block[i/3][j/3][digit] = false;
            }
        }
    }
};
