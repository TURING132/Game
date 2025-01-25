#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:


    bool circularArrayLoop(vector<int>& nums) {
        int fast = 0, slow = 0;
        int l = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur])%l+ l) % l;
        };
        
        for(int i = 0; i < l; i++){
            if(!nums[i]) continue;
            bool pos = nums[i] > 0;
            fast = i;
            slow = i;
            for(int _ = 0; _ < l; _++){
                if(!nums[fast] || !nums[slow] || pos != nums[fast]>0 || pos != nums[slow]>0){ break;}
                fast = next(fast);
                if(!nums[fast] || pos != nums[fast]>0) break;
                fast = next(fast);
                slow = next(slow);
                if(fast == slow && next(slow) != slow) {  return true;}
            }
            int z = i;
            while(nums[z] && nums[z] > 0 == pos){
                int t = next(z);
                nums[z] = 0;
                z = t;
            }
        }

        return false;
    }
};