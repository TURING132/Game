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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode * p1 = head;
        ListNode * mid = findMid(head);
        ListNode * p2 = mid->next;
        mid->next = nullptr;
        p2 = rev(p2);
        ListNode * tmp1, *tmp2;
        while(p1 != nullptr && p2 != nullptr){
            tmp1 = p1->next;
            tmp2 = p2->next;
            p1->next = p2;
            p1 = tmp1;
            p2->next = p1;
            p2 = tmp2;
        }
        return;
    }

    ListNode * rev(ListNode * head) {
        ListNode * prev = nullptr, * cur = head ,* next;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode * findMid(ListNode * head){
        ListNode * f = head, * s = head;
        while(f!=nullptr){
            if(f->next == nullptr) break;
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

};