
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummy = new ListNode(0, head);
        ListNode *  prev = dummy, * cur = head, *next;
        while(cur != nullptr){
            next = cur->next;
            if(cur->val == val){
                if(prev != nullptr) prev->next = next;
            }else{
                prev = cur;
            }
            cur = next;
        }
        return dummy->next;
    }
};