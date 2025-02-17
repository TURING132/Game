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

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0, target;
//         for(int & num : nums) sum+= num;
//         if(sum %2 == 1) return false;
//         else target = sum / 2;

//         int n = nums.size();
//         vector<bool> f(target + 1, false);
//         // [i, j] 前i个物品，这i个物品的价值之和恰好可以为j
//         // f[i, j] = f[i-1][j] || f[i-1][j-nums[i]]
//         f[0] = true;
//         for(int i =1; i <= n; i++){
//             for(int j = target; j >= nums[i-1]; j--){             
//                 f[j] = f[j] || f[j-nums[i-1]];
//             }
//         }

//         return f[target];
//     }
// };


// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0, target;
//         for(int & num : nums) sum+= num;
//         if(sum %2 == 1) return false;
//         else target = sum / 2;

//         int n = nums.size();
//         vector<vector<bool>>f(n+1, vector<bool>(target + 1, false));
//         // [i, j] 前i个物品，这i个物品的价值之和恰好可以为j
//         // f[i, j] = f[i-1][j] || f[i-1][j-nums[i]]
//         for(int i = 0; i <= n; i++)f[i][0] = true;
//         for(int i =1; i <= n; i++){
//             for(int j = 1; j <= target; j++){             
//                 if(j >= nums[i-1]) f[i][j] = f[i-1][j] || f[i-1][j-nums[i-1]];
//                 else f[i][j] = f[i-1][j];
//             }
//         }

//         return f[n][target];
//     }
// };