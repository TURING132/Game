#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if(root)q.push(root);
        while(q.size()){
            int size = q.size();
            Node * tail = nullptr;
            for(int _ = 0; _ < size; _++){
                Node * n = q.front(); q.pop();
                if(n->right) q.push(n->right);
                if(n->left)q.push(n->left);
                n->next = tail;
                tail = n;
            }
        }
        return root;
    }
};