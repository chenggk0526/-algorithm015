class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for (int i = 0; i < max(s.size(), t.size()); ++i) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto key : m) {
            if (key.second != 0) return false;
        }
        return true;

    }
};