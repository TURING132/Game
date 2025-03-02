#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *>q;
        if(root) q.push(root);
        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode * ne = q.front(); q.pop();
                if(ne->right)q.push(ne->right);
                if(ne->left)q.push(ne->left);
                if(i == 0)res.push_back(ne->val);
            }
        }
        return res;
    }
};