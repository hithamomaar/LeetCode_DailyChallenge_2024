class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, int> mp;
        for (auto v : trust) {
            mp[v[1]]++;
            mp[v[0]]--;
        }
        if (n == 1 && trust.empty())
            return 1;
        for (auto [a, b] : mp) {
            if (b == n - 1)
                return a;
        }
        return -1;
    }
};
