class Solution {
public:
    int dp[50];
    int solve(int x) {
        if (x < 0) return 0;
        if (!x) return 1;
        int& ret = dp[x];
        if (~ret) return ret;
        ret = solve(x - 1);
        ret += solve(x - 2);
        return ret;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
};
