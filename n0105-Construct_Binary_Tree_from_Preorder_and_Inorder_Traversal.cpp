#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> val2idx;
        for (int i = 0; i < inorder.size(); i++){
            val2idx[inorder[i]] = i;
        }
        // [beg, end)
        return buildTree(preorder, inorder, val2idx, 0, preorder.size(), 0, preorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int> & inorder, unordered_map<int, int> & val2idx,
        int preBeg, int preEnd, int inBeg, int inEnd) {
        if (preBeg >= preEnd || inBeg >= inEnd) return nullptr;
        TreeNode * root = new TreeNode(preorder[preBeg]);
        int rootIdx = val2idx[preorder[preBeg]];
        int leftLen = rootIdx - inBeg;
        int rightLen = inEnd - rootIdx - 1;
        root->left = buildTree(preorder, inorder, val2idx, preBeg + 1, preBeg + 1 + leftLen, inBeg, inBeg + leftLen);
        root->right = buildTree(preorder, inorder, val2idx, preBeg + 1 + leftLen, preBeg + 1 + leftLen + rightLen, inBeg + leftLen + 1, inEnd);
        return root;            
    } 
};