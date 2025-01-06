
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void flatten(TreeNode* root) {
        TreeNode * cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode * rInL = cur->left; // rightest in left tree
                while (rInL->right != nullptr) rInL = rInL->right;
                rInL->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};