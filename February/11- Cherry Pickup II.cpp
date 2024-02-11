class Solution {
public:
    int dp[75][75][75], n, m;
    int dx[9] = {-1, -1, -1, 1, 1, 1, 0, 0, 0};
    int dy[9] = {-1, 0, 1, -1, 1, 0, -1, 1, 0};
    bool valid(int x, int y) { 
        return 0 <= x && x < m && 0 <= y && y < m;
    }
    int solve(int i, int j, int round, vector<vector<int>>& v) {
        if (round == n) {
            return 0;
        }
        int& ret = dp[i][j][round];
        if (~ret)
            return ret;
        ret = 0;
        for (int k = 0; k < 9; k++) {
            int tox = dx[k] + i;
            int toy = dy[k] + j;
            int tot = v[round][i] + (i != j ? v[round][j] : 0);
            if (valid(tox, toy)) {
                ret = max(ret, solve(tox, toy, round + 1, v) + tot);
            }
        }
        return ret;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return solve(0, m - 1, 0, grid);
    }
};
