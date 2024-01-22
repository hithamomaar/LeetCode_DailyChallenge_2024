class Solution {
public:
    int dp[105][2], n;
    int solve(int idx, bool take, vector<int>& nums) {
        if (idx >= n) return 0;
        int& ret = dp[idx][take];
        if (~ret) return ret;
        ret = solve(idx + 1, 0, nums);
        if (!take) {
            ret = max(ret, solve(idx + 1, 1, nums) + nums[idx]);
        }
        return ret;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0, nums);
    }
};
