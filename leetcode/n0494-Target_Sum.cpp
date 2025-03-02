#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums) sum+= num;
        if(abs(target) > sum || (target + sum) % 2 == 1) return 0;
        int size = (target+ sum) / 2;
        int n = nums.size();
        
        vector<int> f(size + 1);
        f[0] = 1; // 装0的大小只有全都不选
        if(nums[0] <= size) f[nums[0]] += 1; // 选择前0个物品，只有大小为nums[0]的袋子可以装满，写成+1是为了处理大小为0的物品
        for(int i = 1; i < n; i++){ // 注意从1开始，因为前0个物品已经初始化过了
            for(int j = size; j >= nums[i]; j--){
                f[j] = f[j - nums[i]] + f[j]; // 等于选这个物品的总方法数 + 不选这个物品的总方法数
            }
        }
        return f[size];
    }
};