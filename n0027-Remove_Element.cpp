# include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // use two pointer to moev elements
        int fast = 0, slow = 0;
        for(;fast<nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            } 
        } 
        return slow;
    }
};