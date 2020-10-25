class Solution {
public:
    bool isAnagram(string s, string t) {
        // hash
        unordered_map<char, int> m;
        for (int i = 0; i < max(s.size(), t.size()); ++i) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto key : m) {
            if (key.second != 0) return false;
        }
        return true;

        // sort
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
    }
};