#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, p0) == 0, [p0, i) == 1, (p2, len-1] == 2
        int p = nums.size()-1, p2 = nums.size()-1;
        while(p>=0){
            if(nums[p] == 2){
                swap(nums[p], nums[p2]);
                p2--;
            }
            p--;
        }
        int p1 = p2;
        p = p1;
        while(p>=0){
            if(nums[p] == 1){
                swap(nums[p], nums[p1]);
                p1--;
            }
            p--;
        }
    }
};