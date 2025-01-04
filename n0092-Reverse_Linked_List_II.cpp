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
    void reverse(ListNode * head) {
        ListNode * temp, * cur = head, * prev = nullptr;
        while (cur != nullptr) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }        
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy = new ListNode(0, head);
        ListNode * L_prev = dummy; // use L_prev to get L and L_prev

        for (int _ = 0; _ < left - 1; _ ++) {
            L_prev = L_prev->next;
        }
        ListNode * L  = L_prev->next;

        ListNode * R = L;
        for (int _ = 0; _ < right - left; _++) {
            R = R->next;
        }

        ListNode * R_next = R->next; 
        L_prev->next = nullptr;
        R->next = nullptr;
        
        reverse(L);

        L_prev->next = R;
        L->next = R_next;
        
        return dummy->next;
    }
};