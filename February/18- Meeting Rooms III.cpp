class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> val(n, -1), f(n);
        sort(meetings.begin(), meetings.end());
        for (auto x : meetings) {
            long long st = x[0], ed = x[1], mn = LLONG_MAX, idx = -1;
            for (int i = 0; i < n; i++) {
                if (val[i] <= st) val[i] = -1;
                if (val[i] < mn) {
                    mn = val[i], idx = i;
                }
            }
            f[idx]++;
            val[idx] = val[idx] == -1 ? ed : val[idx] + (ed - st);
        }
        int mx = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            if (f[i] > mx) {
                mx = f[i], idx = i;
            }
        }
        return idx;
    }
};
