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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
    void dfs(TreeNode* root, vector<int>& a) {
        if (root->left == NULL && root->right == NULL) {
            a.push_back(root->val);
            return;
        }
        if (root->left != NULL) dfs(root->left, a);
        if (root->right != NULL) dfs(root->right, a);
    }
};
