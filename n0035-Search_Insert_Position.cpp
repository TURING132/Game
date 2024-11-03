# include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // found first index that >= target
        int left = 0, right = nums.size(), mid;
        int pos = nums.size();
        while(left < right){
            // [left, right)
            mid = (left + right) / 2;
            if(nums[mid] == target){
                pos = mid;
                break;
            }else if(nums[mid] > target){
                pos = mid;
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return pos;
    }
};