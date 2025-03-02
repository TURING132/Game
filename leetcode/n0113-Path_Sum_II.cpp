#include <vector>
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
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode * root, int target){
        // target 表示当前子树的总和
        if(root == nullptr || root->val > target) return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && root->val == target) res.push_back(path);
        if(root->left)dfs(root->left, target - root->val);
        if(root->right)dfs(root->right, target - root->val);
        path.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};