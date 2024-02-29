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
    bool ans = true;
    vector<int> lvl[100005];
    bool isEvenOddTree(TreeNode* root) {
        go(root, 0);
        for (int i = 0; i < 100002; i++) {
            for (int j = 1; j < lvl[i].size(); j++) {
                if (i & 1 && lvl[i][j - 1] <= lvl[i][j])
                    return false;
                if (!(i & 1) && lvl[i][j - 1] >= lvl[i][j])
                    return false;
            }
        }
        return ans;
    }
    void go(TreeNode* root, int dep) {
        if (root == NULL)
            return;
        if (root->val % 2 == dep % 2)
            ans = false;
        lvl[dep].push_back(root->val);
        go(root->left, dep + 1);
        go(root->right, dep + 1);
    }
};
