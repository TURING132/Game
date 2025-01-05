struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    TreeNode* hcaHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr; 
        if (root == p || root == q) return root; // return hca
        TreeNode * left = hcaHelper(root->left, p, q);
        TreeNode * right = hcaHelper(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        else if (left == nullptr && right != nullptr) return right; // hca in the right
        else if (left != nullptr && right == nullptr) return left; // hca in the left
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return hcaHelper(root, p, q);
    }
};