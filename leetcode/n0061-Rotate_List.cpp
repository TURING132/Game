#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode * cur = head;
        int n = 1;
        while (cur->next != nullptr) {
            cur = cur->next;
            n ++;
        }
        cur->next = head;
        k %= n;
        cur = head;
        for (int _ = 0; _ < n - k - 1; _++) {
            cur = cur->next;
        }
        ListNode * newHead = cur->next;
        cur->next = nullptr;
        
        return newHead;
    }
};