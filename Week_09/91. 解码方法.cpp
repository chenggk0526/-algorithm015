class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, now = 1;
        for (int i = 1; i < s.size(); ++i) {
            int tmp = now;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') now = pre;
                else return 0;
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                now += pre;
            }
            pre = tmp;
        }
    return now;
    }
};