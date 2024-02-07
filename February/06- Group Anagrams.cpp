class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            mp[x].push_back(i);
        }
        for (auto [s, v] : mp) {
            vector<string> t;
            for (auto idx : v)
                t.push_back(strs[idx]);
            ans.push_back(t);
        }
        return ans;
    }
};
