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
    int ans = -1, mx;
    bool ok = false;
    int findBottomLeftValue(TreeNode* root) {
        go(root, 0);
        ans = -1, ok = false;;
        go(root, 0);
        return ans;
    }
    void go(TreeNode* root, int d) {
        if (root == NULL) return;
        if (d == mx && !ok)
            ans = root->val, ok = true;
        mx = max(mx, d);
        go(root->left, d + 1);
        go(root->right, d + 1);
    }
};
