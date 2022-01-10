/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
#include "iostream"
#include "stack"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "vector"
#include  "math.h"
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0,end = s.size()-1;
        while(start < end){
            if(s[start] == s[end]){
                ++start;
                --end;
            }else{
                return check(start+1,end,s) || check(start,end-1,s);
            }
        }
        return true;
    }
    bool check(int left, int right,string& s){
        for(int i=left,j=right;i<j;--j,++i){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

