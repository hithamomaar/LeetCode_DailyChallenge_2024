class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int num, miss, n = nums.size();
        vector<int> ans, f(n + 1);
        for (auto i : nums) f[i]++;
        for (int i = 1; i <= n; i++) {
            if (!f[i]) miss = i;
            if (f[i] == 2) num = i;
        }
        ans.push_back(num);
        ans.push_back(miss);
        return ans;
    }
};
