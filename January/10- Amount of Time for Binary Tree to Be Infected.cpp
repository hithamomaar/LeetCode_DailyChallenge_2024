/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> adj[100005];
    int ans = 0;
    int amountOfTime(TreeNode* root, int start) {
        go(root);
        vector<int> dis(100005, -1);
        queue<int> q;
        q.push(start);
        dis[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            ans = max(ans, dis[u]);
            q.pop();
            for (auto v : adj[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
    void go(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        go(root->left);
        go(root->right);
    }
};
