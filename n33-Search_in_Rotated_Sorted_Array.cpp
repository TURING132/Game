# include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // always one side is sorted, we can do binary search base on this feature
        // [left, right)
        int left = 0, right = nums.size();
        int middle;
        while(left < right){
            middle = (left + right) / 2;
            if(nums[middle]==target) return middle;
            if(nums[0]<nums[middle]){
                // left side is sorted
                if(target >= nums[0] && target < nums[middle]){
                    // if target larger than nums[0] and less than nums[middle], search on left side
                    right = middle;
                }else{
                    left = middle + 1;
                }
            }else{
                // right side is sorted
                if(target <= nums.back() && target > nums[middle]){
                    // if target smaller than nums[n-1] and larger than nums[midde], search on right side
                    left = middle + 1;
                }else{
                    right = middle;
                }
            }
        }
        return -1;
    }
};