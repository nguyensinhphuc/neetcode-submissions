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

class Codec {
public:

    // Serialize: Cây -> chuỗi
    void serializeHelper(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Deserialize: Chuỗi -> cây
    TreeNode* deserializeHelper(stringstream& ss) {
        string x;
        getline(ss, x, ',');

        if (x == "N") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(x));

        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
