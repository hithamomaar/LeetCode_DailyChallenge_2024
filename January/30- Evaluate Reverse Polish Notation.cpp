class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto i : tokens) {
            if (i == "*" || i == "/" || i == "-" || i == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int res;
                if (i == "*") res = y * x;
                else if (i == "/") res = y / x;
                else if (i == "+") res = y + x;
                else res = y - x;
                st.push(res);
            } else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
