class Solution {
public:
    int n, dp[50005];
    vector<vector<int>> job;
    vector<int> s;
    int solve(int i) {
        if (i >= n) return 0;
        int& ret = dp[i];
        if (~ret) return ret;
        ret = solve(i + 1);
        int l = lower_bound(s.begin(), s.end(), job[i][1]) - s.begin();
        ret = max(ret, solve(l) + job[i][2]);
        return ret;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        s = startTime;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            job.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(job.begin(), job.end());
        sort(s.begin(), s.end());
        return solve(0);
    }
};
