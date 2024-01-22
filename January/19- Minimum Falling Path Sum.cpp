class Solution {
public:
    int n, dp[105][105], OO = 0x3f3f3f3f;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, OO, sizeof dp);
        n = matrix.size();
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix));
        }
        return ans;
    }
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i == n)return 0;
        int& ret = dp[i][j];
        if (ret != OO)return ret;
        ret = solve(i + 1, j, matrix) + matrix[i][j];
        if (valid(i + 1, j + 1))ret = min(ret, solve(i + 1, j + 1, matrix) + matrix[i][j]);
        if (valid(i + 1, j - 1))ret = min(ret, solve(i + 1, j - 1, matrix) + matrix[i][j]);
        return ret;
    }
    bool valid(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n; 
    }
};
