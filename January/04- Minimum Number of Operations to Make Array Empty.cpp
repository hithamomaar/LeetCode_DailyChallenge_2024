class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums) mp[i]++;
        int res = 0;
        for (auto i : mp) {
            if (i.second == 1) return -1;
            int o = i.second / 3;
            int rem = i.second % 3;
            if (rem != 0) o++;
            res += o;
        }
        return res;
    }
};
