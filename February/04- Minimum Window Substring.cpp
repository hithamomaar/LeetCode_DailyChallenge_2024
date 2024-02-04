class Solution {
public:
    map<char, int> a, b;
    bool valid() {
        int c = 0;
        for (auto i : a) {
            if (b.count(i.first) && b[i.first] >= i.second)
                c++;
        }
        return c == a.size();
    }
    string minWindow(string s, string t) {
        for (auto i : t) a[i]++;
        int l, r = 0, ans = 1e9, start = 0;
        for (l = 0; l < s.size(); l++) {
            while (r < s.size() && !valid()) {
                if (a.count(s[r])) {
                    b[s[r]]++;
                }
                r++;
            }
            if (valid() && r - l < ans) {
                ans = r - l;
                start = l;
            }
            if (a.count(s[l])) {
                b[s[l]]--;
                if (!b[s[l]]) {
                    b.erase(s[l]);
                }
            }
        }
        if (ans == 1e9)
            return "";
        return s.substr(start, ans);
    }
};
