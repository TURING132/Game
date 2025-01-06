#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        for( ; i < nums.size(); i++){
            if(j == 0 || nums[j-1]!=nums[i])
                nums[j++] = nums[i];
        }
        return j;
    }
};