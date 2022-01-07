/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int max_count = 0;
        for(const int& num : nums){
            max_count = max(max_count,++counts[num]);
        }

        vector<vector<int>> buckets(max_count+1);
        for(auto& p : counts){
            buckets[p.second].push_back(p.first);
        }

        vector<int> res;
        for(int i= max_count;i >=0 && res.size() < k ;--i){
            for(auto& num : buckets[i]){
                res.push_back(num);
                if(res.size() == k) break;
            }
        }

        return res;

    }
};
// @lc code=end

