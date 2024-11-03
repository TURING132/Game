# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            use range [left, right)
            which mean arr[left] is considered but arr[right] is not.
        */
        int left = 0, right = nums.size();
        int middle;
        while(left < right){
            middle = (left + right) / 2;
            if(nums[middle] == target) return middle;
            else if(nums[middle] > target){
                // nums[midele] is too large, we should update the right bound
                right = middle;
            }
            else{
                // nums[middle] is too small, we shoud update the left bound
                left = middle + 1;
            }
        }
        return -1;
    }
};