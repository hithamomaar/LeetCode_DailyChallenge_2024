class Solution {
public:
    int dp[505][505], n, kk;
    int solve(int idx, int prvlen, vector<int>& v) {
        if (idx >= n) return 0;
        int& ret = dp[idx][prvlen];
        if (~ret) return ret;
        int mx = 0, len;
        ret = 0;
        for (int i = idx; i < n; i++) {
            len = i - idx + 1;
            if (len > kk) break;
            mx = max(mx, v[i]);
            ret = max(ret, solve(i + 1, len, v) + mx * len);
        }
        return ret;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof dp);
        n = arr.size(), kk = k;
        return solve(0, 0, arr);
    }
};
