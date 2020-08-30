/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= leftMax? leftMax = height[left] : ans += (leftMax - height[left]);
                ++left;
            } else {
                height[right] >= rightMax? rightMax = height[right] : ans += (rightMax - height[right]);
                --right;
            }
        }        
        return ans;
    }
};
// @lc code=end

