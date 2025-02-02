#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node *> o2n;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* newNode = new Node(node->val);
        o2n[node] = newNode;
        for(Node * ne : node->neighbors){
            if(o2n.count(ne)){
                newNode->neighbors.push_back(o2n[ne]);
            }else{
                newNode->neighbors.push_back(cloneGraph(ne));
            }
        }
        return newNode;
    }
};