/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, len = height.size();
        stack<int> st;
        for (int i = 0; i < len; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int h = min(height[i], height[l]) - height[cur];
                ans += (i - l - 1) * h;
            }
            st.push(i);
        }
        return ans;

    }
};
// @lc code=end

