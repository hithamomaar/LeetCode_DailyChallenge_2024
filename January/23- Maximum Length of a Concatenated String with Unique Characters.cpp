class Solution {
public:
    int ans = 0, n;
    vector<int> frq;
    int check() {
        int c = 0;
        for (auto i : frq) {
            if (i > 1)
                return 0;
            if (i) c++;
        }
        return c;
    }
    void solve(int idx, vector<string>& v) {
        if (idx == n) {
            ans = max(ans, check());
            return;
        }
        solve(idx + 1, v);
        for (auto i : v[idx]) frq[i - 'a']++;
        solve(idx + 1, v);
        for (auto i : v[idx]) frq[i - 'a']--;
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        frq.resize(26);
        solve(0, arr);
        return ans;
    }
};
