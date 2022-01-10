/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.push_back(nums.back() + 1); //添加一个元素使得总个数是2的倍数
        int l = 0, r = nums.size() / 2 - 1; //组的个数有n / 2个
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid * 2] == nums[mid * 2 + 1]) l = mid + 1; //相等说明分界点在右边区间
            else r = mid;                                       //不相等说明分界点在左边区间        
        }
        return nums[l * 2];
    }
};
// @lc code=end

