/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector< vector<int> > ans;
        vector<int> tmp(3);
        for (int k = 0; k < len - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1, j = len - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0) {
                    while (i < j && nums[i] == nums[++i]);                  
                } else if (sum > 0) {
                    while (i < j && nums[j] == nums[--j]);                   
                } else {
                    tmp[0] = nums[k];
                    tmp[1] = nums[i];
                    tmp[2] = nums[j];
                    ans.push_back(tmp);
                    while (i < j && nums[i] == nums[++i]);
                    while (i < j && nums[j] == nums[--j]);
                }
            }
        }
        return ans; 
    }
};
// @lc code=end

