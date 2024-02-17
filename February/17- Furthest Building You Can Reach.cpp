class Solution {
public:
    vector<int> dif,idx;
    bool ok(int x, int b, int l) {
        vector<int> v;
        for (int i = 0; i <= x; i++) {
            v.push_back(dif[i]);
        }
        sort(v.begin(), v.end());
        for (auto d : v) {
            if (d <= b) b -= d;
            else if (l) l--;
            else {
                return 0;
            }
        }
        return 1;
    }
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size();
        for (int i = 1; i < n; i++) {
            if (h[i - 1] < h[i]) {
                idx.push_back(i);
                dif.push_back(h[i] - h[i - 1]);
            }
        }
        int l = 0, r = dif.size() - 1, lst = 0;
        while (l <= r) {
            int md = (l + r) / 2;
            if (ok(md, bricks, ladders)) {
                lst = idx[md], l = md + 1;
            }
            else
                r = md - 1;
        }
        h.push_back(1e9);
        while (lst < n && h[lst] >= h[lst + 1])
            lst++;
        return lst;
    }
};
