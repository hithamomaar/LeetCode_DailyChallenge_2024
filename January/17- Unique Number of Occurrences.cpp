class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> a, b;
        for (auto i : arr) a[i]++;
        for (auto i : a) b[i.second]++;
        return a.size() == b.size();
    }
};
