#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // s[j] - s[i-1] >= target
        // s[j] >= s[i-1] + target
        vector<int> s(nums.size()+1, 0);
        for(int i =1 ;i <= nums.size();i++){
            s[i] = s[i-1] + nums[i-1];
        }
        int res = INT_MAX;
        for(int i = 1; i < s.size(); i++){
            int t = target + s[i-1];
            auto bound = lower_bound(s.begin(), s.end(), t);
            if(bound != s.end()){
                res = min(res, int(bound - s.begin() - (i-1)));
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};