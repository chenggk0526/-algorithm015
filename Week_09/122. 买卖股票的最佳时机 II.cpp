class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];

        //贪心

        // int n = prices.size(), res = 0;
        // for (int i = 1; i < n; ++i) {
        //     if (prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
        // }
        // return res;        
    }
};