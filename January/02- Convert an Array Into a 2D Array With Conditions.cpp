class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        while (nums.size()) {
            int mx = *max_element(nums.begin(), nums.end());
            vector<int> f(mx + 1), rem, cur;
            for (int i = 0; i < nums.size(); i++) {
                if (!f[nums[i]]) cur.push_back(nums[i]);
                else rem.push_back(nums[i]);
                f[nums[i]]++;
            }
            ans.push_back(cur);
            nums = rem;
        }
        return ans;
    }
};
