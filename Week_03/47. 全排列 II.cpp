class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        vector<bool> used(n, false);
        vector<int> path;
        dfs(nums, n, 0, used, path, res);
        return res;
    }

    void dfs(vector<int>& nums, int n, int depth, vector<bool> used, vector<int> &path, vector<vector<int>> &res) {
        
        if (depth == n) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] || (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])) continue;
            if (!used[i]) {
                path.emplace_back(nums[i]);
                used[i] = true;
                dfs(nums, n, depth + 1, used, path, res);
                used[i] = false;
                path.pop_back();
            }

        }
    }
};