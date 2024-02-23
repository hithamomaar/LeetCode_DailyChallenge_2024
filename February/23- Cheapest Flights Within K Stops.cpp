class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<pair<int, int>> adj[105];
        for (auto v: flights) adj[v[0]].push_back({v[1], v[2]});
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});
        vector<vector<int>> dis(105, vector<int>(105, 1e9));
        dis[src][0] = 0;
        while (!pq.empty()) {
            auto [w, node] = pq.top();
            int u = node.first, step = node.second;
            pq.pop();
            for (auto [v, w2]: adj[u]) {
                if (step <= k && dis[u][step] + w2 < dis[v][step + 1]) {
                    dis[v][step + 1] = dis[u][step] + w2;
                    pq.push({dis[v][step + 1], {v, step + 1}});
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= k + 1; ++i) ans = min(ans, dis[dst][i]);
        if (ans == 1e9)return -1;
        return ans;
    }
};
