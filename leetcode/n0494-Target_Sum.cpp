#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto & num : nums) sum += num;
        if((target + sum)% 2 || abs(target) > sum) return 0;
        int size = (target + sum) / 2;
        vector<int> f(size + 1);
        f[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = size; j >= nums[i]; j--){
                f[j] = f[j] + f[j - nums[i]];
            }
        }
        return f[size];
    }
};