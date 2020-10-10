class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> tmp(26);
        for (auto c : tasks) ++tmp[c - 'A'];
        sort(tmp.rbegin(), tmp.rend());
        int count = 1;
        while (count < tmp.size() && tmp[count] == tmp[0]) count++;
        return max(len, count + (n + 1) * (tmp[0] - 1));
    }
};