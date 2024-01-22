class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26), b(26);
        for (auto i : s) a[i - 'a']++;
        for (auto i : t) b[i - 'a']++;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += max(0, a[i] - b[i]);
        }
        return ans;
    }
};
