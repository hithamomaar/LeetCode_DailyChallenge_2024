class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int x = nums.size() / 3;
        vector<vector<int>> ans(x), emp;
        for (int i = 0; i < nums.size(); i++)
            ans[i / 3].push_back(nums[i]);
        for (auto i : ans) {
            if (i.back() - i[0] > k)
                return emp;
        }
        return ans;
    }
};
