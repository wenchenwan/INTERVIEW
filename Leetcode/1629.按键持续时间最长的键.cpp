/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int MaxTime = releaseTimes[0];
        char pre_char = keysPressed[0];
        for(int i=1;i<releaseTimes.size();++i){
            int duroation = releaseTimes[i] - releaseTimes[i-1];
            if(MaxTime < duroation){
                
                MaxTime = duroation;
                res = keysPressed[i];
            }else if(MaxTime == duroation){
                if(keysPressed[i] > res){
                    res = keysPressed[i];
                }
            }
           
        }

        return res;
    }
};
// @lc code=end

