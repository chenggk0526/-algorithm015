class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(), count = 0;
        vector<bool> dp(len);
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1])) {
                    dp[i] = true;
                    count++;
                } else {
                    dp[i] = false;
                }
            }
        }
        return count;
    }
};