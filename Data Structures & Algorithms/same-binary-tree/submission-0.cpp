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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Cả hai đều rỗng
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Một cây rỗng, một cây không
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Giá trị khác nhau
        if (p->val != q->val) {
            return false;
        }

        // Kiểm tra cả cây con trái và phải
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};