class Solution {
public:
    int numSquares(int n) {
        vector<int> psq, dis(n + 1, -1);
        queue<int> q;
        for (int i = 1; i * i <= n; i++) {
            dis[i * i] = 1;
            q.push(i * i);
            psq.push_back(i * i);
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto i : psq) {
                int num = u + i;
                if (1 <= num && num <= n && dis[num] == -1) {
                    dis[num] = dis[u] + 1;
                    q.push(num);
                }
            }
        }
        return dis[n];
    }
};
