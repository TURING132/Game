#include <vector>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto & num : nums){
            sum += num;
        }
        if(sum % 2) return false;
        int target = sum / 2;
        vector<int>f(target + 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                f[j] = min(f[j], f[j - nums[i]] + nums[i]);
            }
        }
        return f[target] == target;
    }
};