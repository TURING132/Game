#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // (i, j) 表示前i个物品，体积 <= j，这里v = w
        int sum = 0;
        for(int s : stones) sum += s;
        int target = sum / 2;

        int n = stones.size();
        vector<int> f(target + 1);
        for(int i = 1; i <= n; i++){
            for(int j = target; j >= stones[i-1]; j--){
                f[j] = max(f[j], f[j-stones[i-1]] + stones[i-1]);
            }
        }

        return sum - (f[target] * 2);
    }
};