class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> oc;
        for (auto i : arr) oc[i]++;
        vector<int> frq_oc;
        for (auto [val, f] : oc) {
            frq_oc.push_back(f);
        }
        sort(frq_oc.begin(), frq_oc.end());
        for (int i = 1; i < frq_oc.size(); i++) frq_oc[i] += frq_oc[i - 1];
        int rem =
            frq_oc.size() - (upper_bound(frq_oc.begin(), frq_oc.end(), k) - frq_oc.begin());
        return rem;
    }
};
