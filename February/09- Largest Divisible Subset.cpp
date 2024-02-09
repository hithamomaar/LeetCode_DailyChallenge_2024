class Solution {
public:
    int n;
    vector<int> ans, v;
    int dp[1005][1005];
    int solve(int idx, int lst) {
        if (idx > n) return 0;
        int& ret = dp[idx][lst];
        if (~ret)
            return ret;
        ret = solve(idx + 1, lst);
        if (v[idx] % v[lst] == 0)
            ret = max(ret, solve(idx + 1, idx) + 1);
        return ret;
    }
    void build(int idx, int lst) {
        if (idx > n) return;
        int& ret = dp[idx][lst];
        int op1 = solve(idx + 1, lst);
        int op2 = (v[idx] % v[lst] == 0) ? solve(idx + 1, idx) + 1 : 0;
        if (ret == op1)
            build(idx + 1, lst);
        else { // op2
            ans.push_back(v[idx]);
            build(idx + 1, idx);
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        n = nums.size();
        sort(nums.begin(), nums.end());
        v.resize(n + 1);
        for (int i = 1; i <= n; i++) v[i] = nums[i - 1];
        v[0] = 1;
        int mx = solve(1, 0);
        build(1, 0);
        return ans;
    }
};
