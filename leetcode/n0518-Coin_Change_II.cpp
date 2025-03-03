#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // f(i, j) 表示前i个物品，且体积不超过j的选法
        int n = coins.size();
        vector<int> f(amount + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = coins[i-1]; j <= amount; j++){
                f[j] += f[j-coins[i-1]]; // 使用当前硬币，因为可以重复使用，要写成 f[i]而不是f[i-1]
            }
        }
        return f[amount];
    }
};
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         // f(i, j) 表示前i个物品，且体积不超过j的选法
//         int n = coins.size();
//         vector<vector<int>> f(n + 1, vector<int>(amount + 1));
//         f[0][0] = 1;
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j <= amount; j++){
//                 f[i][j] = f[i-1][j]; // 不使用这个硬币
//                 if(j >= coins[i-1]) f[i][j] += f[i][j-coins[i-1]]; // 使用当前硬币，因为可以重复使用，要写成 f[i]而不是f[i-1]
//             }
//         }
//         return f[n][amount];
//     }
// };