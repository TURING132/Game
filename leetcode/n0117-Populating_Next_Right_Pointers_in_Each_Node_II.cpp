#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        Node * curHead = root;
        Node * nextHead = nullptr;
        Node * nextTail = nullptr;     
        while (curHead != nullptr) {
            nextHead = nullptr;
            nextTail = nullptr;
            for (Node * curTail = curHead; curTail != nullptr; curTail = curTail->next) {
                if (curTail->left) {
                    if (nextTail != nullptr) {nextTail->next = curTail->left; nextTail = nextTail->next;}
                    if (nextHead == nullptr) {nextHead = curTail->left; nextTail = nextHead;}
                }
                if (curTail->right) {
                    if (nextTail != nullptr) {nextTail->next = curTail->right; nextTail = nextTail->next;}
                    if (nextHead == nullptr) {nextHead = curTail->right; nextTail = nextHead;}
                }
            }
            curHead = nextHead;
        }
        return root;
    }
};