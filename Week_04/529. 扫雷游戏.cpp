class Solution {
public:
    int dx[8] = {0,1,0,-1,1,1,-1,-1};
    int dy[8] = {1,0,-1,0,1,-1,1,-1};

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int cnt = 0;
        for(int k = 0; k < 8; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            cnt += board[x][y] == 'M';
        }
        
        if(cnt > 0)
        {
            board[i][j] = cnt +'0';
            return;
        }
        board[i][j] = 'B';
        for(int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') continue;
            dfs(board, x, y);
            }
        }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M') board[x][y] = 'X';
        else dfs(board, x, y);
        return board;
    }
};