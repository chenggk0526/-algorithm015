class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n;) {
            int k = intervals[i][1], j = i + 1;
            while (j < n && intervals[j][0] <= k) k = max(k, intervals[j++][1]);
            res.push_back({intervals[i][0], k});
            i = j;
        }
        return res;
    }
};