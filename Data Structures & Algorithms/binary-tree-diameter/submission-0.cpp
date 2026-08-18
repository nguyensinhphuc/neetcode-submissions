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
    int ans = 0;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        // Số cạnh của đường đi qua node hiện tại
        ans = max(ans, left + right);

        // Chiều cao tính theo số node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};