class Solution {
public:
    int r, c, dp[55][55][55], mod = 1e9 + 7;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int solve(int i, int j, int rem) {
        if (rem < 0) return 0;
        if (i < 0 || j < 0 || i >= r || j >= c) return 1;
        int& ret = dp[i][j][rem];
        if (~ret) return ret;
        ret = 0;
        for (int k = 0; k < 4; k++) {
            ret = (ret + solve(i + dx[k], j + dy[k], rem - 1) % mod) % mod;
        }
        return ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m, c = n;
        memset(dp, -1, sizeof dp);
        return solve(startRow, startColumn, maxMove);
    }
};
