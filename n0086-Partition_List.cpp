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
    ListNode* partition(ListNode* head, int x) {
        ListNode * dummy1 = new ListNode(0, head);
        ListNode * dummy2 = new ListNode(0, nullptr);
        ListNode * ptr2 = dummy2;

        ListNode * prev = dummy1, * cur = dummy1->next, * next = cur == nullptr ? nullptr : cur->next;
        while (cur != nullptr) {
            if (cur->val >= x) {
                prev->next = next;
                ptr2->next = cur;
                ptr2 = ptr2->next;
            } else {
                prev = cur;

            }
            cur = next;
            next = cur == nullptr ? nullptr : cur->next;
        }
        ptr2->next = nullptr; // make sure the end of new linklist
        prev->next = dummy2->next;

        ListNode * res = dummy1->next;
        delete dummy1, dummy2;
        return res;
    }
};