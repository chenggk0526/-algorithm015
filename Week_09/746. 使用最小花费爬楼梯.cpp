class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n, 0);
        // dp[1] = min(cost[0], cost[1]);
        // for (int i = 2; i < n; ++i) {
        //     dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i-1]);
        // }
        // return dp[n-1];
        // }
        int n = cost.size(), pre1 = 0, pre2 = min(cost[0], cost[1]);
        for (int i = 2; i < n; ++i) {
            int cur = min(pre2 + cost[i], pre1 + cost[i-1]);
            pre1 = pre2;
            pre2 = cur;
        }
        return pre2;
    }
};