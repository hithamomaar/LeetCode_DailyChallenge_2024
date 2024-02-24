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
        void clear(int x) {
            Group_sz[x] = 1;
            parent[x] = x;
        }
        bool is_same_set(int x, int y) {
            return find_leader(x) == find_leader(y);
        }
        int get_size(int x) { return Group_sz[find_leader(x)]; }
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,int firstPerson) {
        vector<int> ans;
        map<int, vector<pair<int, int>>> mp;
        for (auto v : meetings) {
            mp[v[2]].push_back({v[0], v[1]});
        }
        DSU dsu(n + 5);
        dsu.union_sets(0, firstPerson);
        for (auto [w, edg] : mp) {
            set<int> used;
            for (auto [u, v] : edg) {
                dsu.union_sets(u, v);
                used.insert(v), used.insert(u);
            }
            for (auto i : used) {
                if (!dsu.is_same_set(0, i)) dsu.clear(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dsu.is_same_set(0, i)) ans.push_back(i);
        }
        return ans;
    }
};
