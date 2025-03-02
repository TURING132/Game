#include <cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * h;
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int res, i = 1;
        for(ListNode * p = h; p; p = p->next){
            if(rand() %  i == 0) res = p->val;
            i++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */