class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (auto i : nums) {
            int l = lower_bound(lis.begin(), lis.end(), i) - lis.begin();
            if (l == lis.size()) lis.push_back(i);
            else lis[l] = i;
        }
        return lis.size();
    }
};
