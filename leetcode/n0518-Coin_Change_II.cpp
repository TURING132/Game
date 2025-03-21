#include <vector>
using namespace std;

typedef unsigned long long LL;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);
        f[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] = (LL)f[j] +  f[j - coins[i]];
            }
        }
        return f[amount];
    }
};