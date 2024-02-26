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
    vector<int> a[105], b[105];
    bool isSameTree(TreeNode* p, TreeNode* q) {
        go(p, 0, 0), go(q, 0, 1);
        for (int i = 0; i <= 100; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    void go(TreeNode* t, int dep, bool f) {
        if (t == NULL) {
            f ? a[dep].push_back(-1e6) : b[dep].push_back(-1e6);
            return;
        }
        f ? a[dep].push_back(t->val) : b[dep].push_back(t->val);
        go(t->left, dep + 1, f);
        go(t->right, dep + 1, f);
    }
};
