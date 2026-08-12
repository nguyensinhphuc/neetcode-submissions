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
    void inorder(TreeNode* root, int& k, int& ans) {
        if (root == nullptr) {
            return;
        }

        // Duyệt cây con trái
        inorder(root->left, k, ans);

        // Xử lý node hiện tại
        k--;

        if (k == 0) {
            ans = root->val;
            return;
        }

        // Duyệt cây con phải
        inorder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
