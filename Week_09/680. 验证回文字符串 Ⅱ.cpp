class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        int del = 0;
        while (left < right) {
            if (s[left] != s[right]) return check(s, left + 1, right) || check(s, left, right - 1);
            left++;
            right--;
        }
        return true;
    }
    bool check(string &s, int left, int right) {
        if (left >= right) return true;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};