class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prf(n);
        for (int i = 0; i < n; i++) {
            prf[i] = nums[i];
            if (i) prf[i] += prf[i - 1];
        }

        for (int i = n - 1; i > 1; i--) {
            if (nums[i] < prf[i - 1])
                return prf[i];
        }
        return -1;
    }
};
