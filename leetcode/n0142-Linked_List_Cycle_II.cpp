struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * s = head, *f = head, *p;
        while(f!= nullptr){
            s= s->next;
            if(f->next == nullptr) return nullptr;
            f = f->next->next;
            if(f == s){
                p = head;
                while(p!=s){
                    p = p->next;
                    s = s->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};