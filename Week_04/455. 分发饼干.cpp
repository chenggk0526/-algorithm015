class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0, m = g.size(), n = s.size();
        while (child < m && cookie < n) {
            if (g[child] <= s[cookie]) child++;
            cookie++;
        }
        return child;
    }
};