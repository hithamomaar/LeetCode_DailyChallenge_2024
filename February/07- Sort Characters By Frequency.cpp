class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        for (auto i : s) mp[i]++;
        for (auto [ch, oc] : mp) {
            v.push_back({oc, ch});
        }
        sort(v.rbegin(), v.rend());
        for (auto [oc, ch] : v) {
            while (oc--) ans += ch;
        }
        return ans;
    }
};
