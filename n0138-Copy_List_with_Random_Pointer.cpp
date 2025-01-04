#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> o2n; // hash map from old to new
        for (Node * ptr = head; ptr != nullptr; ptr = ptr->next) {
            Node * newNode = new Node(ptr->val);
            o2n[ptr] = newNode;
        }
        for (Node * ptr = head; ptr != nullptr; ptr = ptr->next) {
            o2n[ptr]->next = o2n[ptr->next];
            o2n[ptr]->random = o2n[ptr->random];
        }
        return o2n[head];
    }
};