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
    vector<int> f;
    int pseudoPalindromicPaths(TreeNode* root) {
        f.resize(10);
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        f[root->val]++;
        if (root->left == NULL && root->right == NULL) {//leaf
            int d = 0;
            for (int i = 1; i <= 9; i++) d += (f[i] & 1);
            if (d <= 1) ans++;
        }
        dfs(root->left);
        dfs(root->right);
        f[root->val]--;
    }
};
