#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)return false;
        int left = 0, right = nums.size(), mid = 0;
        // [left, right)
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[left] && nums[mid] == nums[right-1]){
                // if any side inequal to mid, we can find a sorted side
                // 111123411 -> left side sorted
                // 234111111 -> right side is sorted
                // 111111234 -> left side is sorted 
                // if mid == left == right, no sure which side sorted
                // 111112111
                left++;
                right--;
            }else if(nums[mid] >= nums[left]){
                // left side is sorted
                if(nums[mid] > target && nums[left] <= target){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }else{
                // right side is sorted
                if(nums[mid] < target && nums[right-1] >= target){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
        }
        return false;
    }
};


int main(){
    vector<int> vec = {1};
    Solution solution;
    solution.search(vec, 1);
}