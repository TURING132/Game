#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }

    int robRange(const vector<int> & nums, int start, int end){
        // [start, end]
        vector<int> f(nums.size());
        f[start] = nums[start];
        f[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++){
            f[i] = max(f[i-1], f[i-2]+nums[i]);
        }
        return f[end];
    }
};