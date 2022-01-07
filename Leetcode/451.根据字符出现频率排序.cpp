/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include "iostream"
#include "stack"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "vector"
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        int max_count = 0;
        for(char& ch : s){
            max_count = max(max_count,++counts[ch]);
        }
        vector<vector<char>> buckets(max_count+1);
        for(auto& p : counts){
            buckets[p.second].push_back(p.first);
        }
        string res;
        for(int i=max_count;i>=0;i--){
            for(auto& ch : buckets[i]){
                res = res + string(i,ch);
            }
        }
        return res;
    }
};
// @lc code=end

