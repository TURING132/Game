#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // keep find toward higher place
        int l = 0, r = nums.size() - 1, mid;
        while(l < r) {
            mid = l + r >> 1;
            if(mid == nums.size() ? true : nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};