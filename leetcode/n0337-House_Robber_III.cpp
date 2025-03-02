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
    pair<int, int> dfs(TreeNode * root){ // 返回抢劫和不抢劫的最大值
        if(!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 如果抢劫，后面不能抢劫
        int rob = root->val + left.second + right.second;
        // 如果不抢劫，可以选择抢劫或者不抢劫
        int not_rob = max(left.first, left.second) + max(right.first, right.second);
        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};