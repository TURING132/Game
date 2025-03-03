#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // f[i, j] 表示前i个硬币，凑出j的最小值
        int n = coins.size();
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                if(f[j-coins[i]] != INT_MAX)
                    f[j] = min(f[j], f[j-coins[i]] + 1);
            }
        }
        if(f[amount] == INT_MAX) return -1;
        return f[amount];
    }
};