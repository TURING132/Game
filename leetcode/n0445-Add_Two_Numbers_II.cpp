
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * reverse(ListNode* l){
        ListNode * prev = nullptr, * cur = l, * next;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * a = reverse(l1);
        ListNode * b = reverse(l2);
        int t = 0;
        ListNode * c = new ListNode(0, nullptr);
        ListNode * pa = a, * pb = b, *pc = c;
        while(pa|| pb) {
            if(pa) {t+= pa->val; pa = pa->next;}
            if(pb) {t+= pb->val; pb = pb->next;}
            pc->next = new ListNode(t%10);
            pc = pc->next;
            t /= 10;
        }
        if(t)pc->next = new ListNode(t);
        ListNode * res = c->next;
        delete c;
        return reverse(res);
    }
};