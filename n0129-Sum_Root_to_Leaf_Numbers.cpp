
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
    int sumHelper(TreeNode * root, int pre) {
        if (root == nullptr) return 0;
        // if leaf, return sum
        if (root->left == nullptr && root->right == nullptr) return pre * 10 + root->val;
        // if not leaf, return sum of path
        int sum = 0;
        if (root->left != nullptr) sum += sumHelper(root->left, pre*10 + root->val);
        if (root->right != nullptr) sum += sumHelper(root->right, pre*10 + root->val);
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return sumHelper(root, 0);
    }
};