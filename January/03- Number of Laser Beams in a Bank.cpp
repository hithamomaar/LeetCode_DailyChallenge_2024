class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prv = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') cnt++;
            }
            ans += cnt * prv;
            if (cnt > 0) prv = cnt;
        }
        return ans;
    }
};
