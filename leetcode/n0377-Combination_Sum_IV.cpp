#include <vector>
using namespace std;
typedef unsigned long long LL;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1);
        f[0] = 1;
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0)
                    f[i] = (LL) f[i] + f[i - nums[j]];
            }
        }
        return f[target];
    }
};


