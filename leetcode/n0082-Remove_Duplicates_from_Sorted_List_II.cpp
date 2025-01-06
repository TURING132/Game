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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0, head);
        ListNode * L_prev = dummy;
        ListNode * L = L_prev->next;
        ListNode * R = L == nullptr ? nullptr : L->next;
        while (L_prev != nullptr && L != nullptr && R != nullptr) {
            bool found = false;
            while (R != nullptr && L->val == R->val) {
                found  = true;
                R = R->next;
            }
            if(found) {
                L_prev->next = R;
            }else{
                L_prev = L_prev->next;
            }
            L = L_prev->next;
            R = L == nullptr ? nullptr : L->next;
        }
        return dummy->next;

    }
};