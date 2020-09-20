class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int ans = 0, x = 0, y = 0, di = 0;
        set<pair<int, int>> obstaclesSet;
        for (auto obstacle : obstacles) {
            obstaclesSet.insert(make_pair(obstacle[0], obstacle[1]));
        }
        for (auto cmd : commands) {
            if (cmd == -2) di = (di + 3) % 4;
            else if (cmd == -1) di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstaclesSet.find(make_pair(nx, ny)) == obstaclesSet.end()) {
                        x = nx;
                        y = ny;
                        ans = std::max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};