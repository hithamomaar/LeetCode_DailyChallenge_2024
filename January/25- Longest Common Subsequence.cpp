class Solution {
public:
    int dp[1005][1005];
    int solve(int i, int j, string& x, string& y) {
        if (i == x.size() || j == y.size())
            return 0;
        int& ret = dp[i][j];
        if (~ret)
            return ret;
        if (x[i] == y[j]) {
            return ret = 1 + solve(i + 1, j + 1, x, y);
        }
        return ret = max(solve(i + 1, j, x, y), solve(i, j + 1, x, y));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, text1, text2);
    }
};
