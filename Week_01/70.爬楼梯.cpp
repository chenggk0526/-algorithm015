/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        long long p = 0, q = 0, r = 1;
        for (int i = 0; i < n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
// @lc code=end

