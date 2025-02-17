#include <vector>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, target;
        for(int & num : nums) sum+= num;
        if(sum %2 == 1) return false;
        else target = sum / 2;

        int n = nums.size();
        // 看成 target 大小的背包能否装满
        // target 最大如果能装 target，即成功
        vector<int> f(target + 1, 0);
        // [i, j] 前i个物品，不超过j的最大target
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                f[j] = max(f[j], f[j - nums[i]]+nums[i]);
            }
        }
        return f[target] == target;
    }
};