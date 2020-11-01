class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) return true;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }
        return true;
    }
};