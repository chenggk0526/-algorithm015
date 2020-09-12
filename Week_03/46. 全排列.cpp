class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (nums.empty()) return res;
        vector<bool> used(n, false);
        vector<int> path;
        dfs(nums, n, 0, used, path, res);
        return res;
    }

    void dfs(vector<int>& nums, int n, int depth, vector<bool> used, vector<int> &path, vector<vector<int>> &res) {
        
        if (depth == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, n, depth + 1, used, path, res);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};