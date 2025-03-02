#include <vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // f(i, j) 表示前i个物品，且体积不超过j的选法
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1));
        f[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                for(int k = 0; k * coins[i-1] <= j; k++){ // 对使用k个coin进行枚举，相加
                    f[i][j] = f[i][j] + f[i-1][j - coins[i-1] * k];
                }
            }
        }
        return f[n][amount];
    }
};