#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> val2idx;
        int postIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            val2idx[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, val2idx, 0, inorder.size(), postIdx);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& val2idx,
        int inBeg, int inEnd, int & postIdx) {
        if (inBeg >= inEnd) return nullptr;

        int val = postorder[postIdx--];
        TreeNode * root = new TreeNode(val);
        int rootIdx = val2idx[val];

        root->right = buildTree(inorder, postorder, val2idx, rootIdx + 1, inEnd, postIdx);
        root->left = buildTree(inorder, postorder, val2idx, inBeg, rootIdx, postIdx);
        return root;
    }
};