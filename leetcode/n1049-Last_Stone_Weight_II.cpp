#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto & s : stones) sum += s;
        int target = sum / 2;
        vector<int> f(target + 1);
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                f[j] = max(f[j], f[j - stones[i]] + stones[i]);
            }
        }

        return sum - f[target] * 2;
    }
};