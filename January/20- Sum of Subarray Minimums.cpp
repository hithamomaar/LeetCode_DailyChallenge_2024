class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size(), mod = 1e9 + 7;
        vector<long long> l(n), r(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.size()) l[i] = i - st.top();
            else l[i] = i + 1;
            st.push(i);
        }
        while (st.size()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size()) r[i] = st.top() - i;
            else r[i] = n - i;
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (l[i] * r[i] * arr[i]) % mod) % mod;
        }
        return (int)ans;
    }
};
