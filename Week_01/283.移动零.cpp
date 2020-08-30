/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for (int slowIdex = 0, cur = 0; cur < len; ++cur) {
            if (nums[cur] != 0) {
                swap(nums[slowIdex++], nums[cur]);
            }
        }
    }
};
// @lc code=end

