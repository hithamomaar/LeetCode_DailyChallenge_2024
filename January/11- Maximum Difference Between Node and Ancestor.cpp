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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        go(root, root->val, root->val);
        return ans;
    }
    void go(TreeNode* root, int mn, int mx) {
        if (root == NULL) {
            ans = max(ans, abs(mn - mx));
            return;
        }
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        go(root->left, mn, mx);
        go(root->right, mn, mx);
    }
};
