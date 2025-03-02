#include <iostream>
using namespace std;

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
    int res = 0;
    void dfs(TreeNode * root, bool left){
        if(!root) return;
        if(root->left)dfs(root->left, true);
        if(root->right)dfs(root->right, false);
        if(root->left == nullptr && root->right == nullptr && left) res += root->val;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return res;
    }
};