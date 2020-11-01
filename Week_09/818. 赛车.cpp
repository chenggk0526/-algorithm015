class Solution {
public:
    int dp[10001];
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if (target + 1 == (1 << n)) {
            dp[target] = n;
        } else {
            dp[target] = n + 1 + racecar((1 << n) - 1 - target);
            for (int m = 0; m < n - 1; ++m) {
                dp[target] = min(dp[target], n + m + 1 + racecar(target- (1 << (n - 1)) + (1 << m)));
            }
        }
        return dp[target];
    }
};