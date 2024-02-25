class Solution {
public:
    struct DSU {
        vector<int> parent, Group_sz;
        DSU(int n) {
            Group_sz.resize(n + 5), parent.resize(n + 5);
            for (int i = 1; i <= n; i++) {
                parent[i] = i, Group_sz[i] = 1;
            }
        }
        int find_leader(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find_leader(parent[x]);
        }
        void union_sets(int x, int y) {
            x = find_leader(x);
            y = find_leader(y);
            if (x == y) return;
            if (Group_sz[x] < Group_sz[y]) swap(x, y);
            Group_sz[x] += Group_sz[y];
            parent[y] = x;
        }
        int get_size(int x) { return Group_sz[find_leader(x)]; }
    };
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int mx = 0, n = nums.size();
        for (auto x : nums) mx = max(mx, x);

        vector<int> factors[mx + 1], adj[mx + 1];
        for (int i = 2; i <= mx; i++) {
            if (factors[i].empty()) {
                for (int j = i; j <= mx; j += i) factors[j].push_back(i);
            }
        }
        for (int idx = 0; idx < n; idx++) {
            for (auto j : factors[nums[idx]]) adj[j].push_back(idx + 1);
        }

        DSU dsu(n+5);
        for (int i = 2; i <= mx; i++) {
            for (int j = 1; j < adj[i].size(); j++) {
                dsu.union_sets(adj[i][j], adj[i][j - 1]);
            }
        }
        return dsu.get_size(1) == n;
    }
};
