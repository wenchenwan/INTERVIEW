/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
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
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        int size = s.size() - 1;
        string res = "";
        for(int i=0;i<n;++i){
            int start_s = 0,start_dic = 0;
            while(start_s <= size && start_dic < dictionary[i].size()){
                if(dictionary[i][start_dic] == s[start_s]){
                    start_dic++;
                    start_s++;
                }else{
                    start_s++;
                } 
            }
            if(start_dic == dictionary[i].size() && start_dic >= res.size()){
                if(start_dic > res.size()){
                    res = dictionary[i];
                }else if(start_dic == res.size() && dictionary[i] < res){
                    res = dictionary[i];
                }
            }
        }

        return res;
    }
};
// @lc code=end

