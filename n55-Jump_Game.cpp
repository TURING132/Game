#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        int cur = 0;
        while(cur <= right){
            if(right >= nums.size() - 1) return true;
            right = max(right, cur + nums[cur]);
            cur ++;
        }
        return false;
    }
};