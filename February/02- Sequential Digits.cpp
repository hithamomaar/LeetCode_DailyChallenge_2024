class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> nums, ans;
        for (int i = 0; i < s.size(); i++) {
            string x = "";
            for (int j = i; j < s.size(); j++) {
                x += s[j];
                nums.push_back(stoi(x));
            }
        }
        sort(nums.begin(), nums.end());
        int lo = lower_bound(nums.begin(), nums.end(), low) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), high) - nums.begin();

        for (int i = lo; i < up; i++)
            ans.push_back(nums[i]);
        
        return ans;
    }
};
