class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> a(n, string(n, '.'));
        vector<int> queen(n, 0);
        vector<int> pie(2 * n, 0);
        vector<int> na(2 * n, 0);
        dfs(res, 0, n, a, queen, pie, na);
        return res;
    }

    void dfs(vector<vector<string>> &res, int row, int n, vector<string> a, vector<int> queen,
    vector<int> pie, vector<int> na) {
        if (row == n) {
            res.emplace_back(a);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!queen[i] && !pie[row - i + n] && !na[row + i]) {
                queen[i] = pie[row - i + n] = na[row + i] = 1;
                a[row][i] = 'Q';
                dfs(res, row + 1, n, a, queen, pie, na);
                a[row][i] = '.';
                queen[i] = pie[row - i + n] = na[row + i] = 0;
            }
        }
    }
};