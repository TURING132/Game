#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int> f(n); // 表示前[0, i]个房间偷到的最大收入
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for(int i = 2; i <= n; i++){
            f[i] = max(f[i-2] + nums[i], f[i-1]);
        }
        return f[n];
    }
};