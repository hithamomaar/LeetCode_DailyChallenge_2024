class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a, b, f1(26), f2(26);
        for (auto i : word1) f1[i - 'a']++;
        for (auto i : word2) f2[i - 'a']++;
        for (int i = 0; i < 26; i++) {
            int c = 0;
            if (f1[i]) a.push_back(f1[i]), c++;
            if (f2[i]) b.push_back(f2[i]), c++;
            if (c == 1)
                return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};
