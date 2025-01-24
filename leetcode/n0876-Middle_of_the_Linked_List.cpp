struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * f = head, * s = head;
        while(f!=nullptr){
            if(f->next == nullptr) break;
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};