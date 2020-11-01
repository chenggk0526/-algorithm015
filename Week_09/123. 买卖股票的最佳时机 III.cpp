class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0][0] = dp[i-1][0][0];
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]);
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]);
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
            dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][1][1] + prices[i]);
        }
        int a = max(dp[n-1][0][0], dp[n-1][0][1]);
        int b = max(dp[n-1][1][0], dp[n-1][1][1]);
        return max(max(a, b), dp[n-1][2][0]);
    }
};