class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        vector<int> a(1e5 + 5), b(1e5 + 5);
        for (auto i : matches) {
            a[i[0]]++;
            b[i[1]]++;
        }
        for (int i = 1; i <= 1e5; i++) {
            if (a[i] && !b[i]) ans[0].push_back(i);
            if (b[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};
