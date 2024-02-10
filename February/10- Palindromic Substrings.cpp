class Solution {
public:
    bool check(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string x;
            for (int j = i; j < n; j++) {
                x += s[j];
                ans += check(x);
            }
        }
        return ans;
    }
};
