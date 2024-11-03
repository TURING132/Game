# include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int left = 0, right = nums.size(), mid;
        // try to find a target
        int found_index = -1;
        while(left<right){
            // [left, right)
            mid = (left + right) / 2;
            if(nums[mid] == target){
                found_index = mid;
                first = found_index;
                last = found_index;
                break;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        if(found_index != -1){
            // find the first on left
            left = 0; right = found_index;
            while(left<right){// nums[mid] <= target
                mid = (left + right) / 2;
                if(nums[mid] == target){
                    first = mid;
                    right = mid;
                }else{
                    left = mid+1;
                }
            }
            // find the last on right
            left = found_index+1; right = nums.size();
            // nums[mid] only possible < or == target
            while(left<right){// nums[mid]>= target
                mid = (left + right) / 2;
                if(nums[mid] == target){
                    last = mid;
                    left = mid+1;
                }else{
                    right = mid;
                }
            }

        }
        return {first,last};;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int  target = 6;
    solution.searchRange(nums, target);
    return 0;
}