class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP
        // int n = nums.size();
        // if (n == 0) return 0;
        // vector<int> dp(n, 1);
        // int res = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);               
        //     }
        //     res = max(res, dp[i]);
        // }
        // return res;

        int n = nums.size(), res = 0;
        vector<int> a(n, 0);
        for (auto num : nums) {
            int i = 0, j = res;
            while (i < j) {
                int mid = (i + j) / 2;
                if (a[mid] < num) i = mid + 1;
                else j = mid;
            }
            a[i] = num;
            if (res == j) res++;
        }
        return res;
    }
};