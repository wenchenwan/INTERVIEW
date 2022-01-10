/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = 5000;
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[start] == nums[mid]){
                res = min(res,nums[start]);
                ++start;
            }else if(nums[mid] <= nums[end]){
                // 右侧有序
                res = min(res,nums[mid]);
                end = mid - 1;
            }else{
                // 左侧有序
                res = min(res,nums[start]);
                start = mid + 1;
            }
        }
        return res;
    }
};
// @lc code=end

