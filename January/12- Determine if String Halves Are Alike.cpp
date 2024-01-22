class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            s[i] = tolower(s[i]);
            if (i < n / 2) x += isv(s[i]);
            else y += isv(s[i]);
        }
        return x == y;
    }
    bool isv(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
};
