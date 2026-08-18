/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* node, int maxValue) {
        if (node == nullptr) {
            return 0;
        }

        int good = 0;

        if (node->val >= maxValue) {
            good = 1;
        }

        maxValue = max(maxValue, node->val);

        return good
             + dfs(node->left, maxValue)
             + dfs(node->right, maxValue);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};