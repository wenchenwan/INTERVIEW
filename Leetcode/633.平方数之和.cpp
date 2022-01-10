/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
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
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        int low = 0,high = n;
        while(low <= high){
            if(low*low + high*high == c){
                return true;
            }
            if(low*low < c - high*high) ++low;
            if(low*low > c - high*high) --high;
        }
        return false;

    }
};
// @lc code=end

