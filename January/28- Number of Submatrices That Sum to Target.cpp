class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pr(n + 5, vector<int>(m + 5));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] +
                           matrix[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int ii = i; ii <= n; ii++) {
                    for (int jj = j; jj <= m; jj++) {
                        int sum = pr[i - 1][j - 1] + pr[ii][jj] -
                                  pr[i - 1][jj] - pr[ii][j - 1];
                        if (sum == target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
