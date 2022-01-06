/**
 * 1576. 替换所有的问号
 * 
 * @file Leetcode1576.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "iostream"
using namespace std;
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        
        for(int i=0;i<n;++i){
            if(s[i] == '?')
                for(char ch='a';ch < 'd';++ch){
                    if((i > 0) && (s[i-1] == ch) || ((i<n-1) && (s[i+1] == ch))){
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
        }
        return s;
    }
};