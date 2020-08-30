/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int h = height.size() - 1;
        int maxArea = 0;
        for (int i = 0,  j = h; i < j;) {
            int minh = height[i] < height[j] ? height[i++] : height[j--];
            int area = (j - i + 1) * minh;
            maxArea = max(maxArea, area);
        }
        return maxArea;       
    }
};
// @lc code=end

