class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k <= 0 || n < k) return res; 
        vector<int> path;
        dfs(n, k, 1, res, path);
        return res;
    }

    void dfs(int n, int k, int begin, vector<vector<int>> &res, vector<int> &path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            dfs(n, k, i + 1, res, path);
            path.pop_back();
        }
    }
};