class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        dfs(res, queens, n, 0, 0, 0, 0);
        return res;
    }

    void dfs(vector<vector<string>> &res, vector<int> &queens, int n, int row, int cols, int ld, int rd) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            res.push_back(board);
        }
        int bits = ~(cols | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pos = bits & -bits;
            bits &= (bits - 1);
            int col = __builtin_ctz(pos);
            queens[row] = col;
            dfs(res, queens, n, row + 1, cols | pos, (ld | pos) << 1, (rd | pos) >> 1);
            queens[row] = -1; 
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        vector<string> board;
        for (auto queen : queens) {
            string row = string(n, '.');
            row[queen] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};