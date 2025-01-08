#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the first num <= nums[r]
        // because first half > nums[r], right half <= [r], we want to find fisrt num in right half
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (nums[mid] <= nums[r]) r = mid;
            else l = mid + 1;
        }
        return l;

    }
};