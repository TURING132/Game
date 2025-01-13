#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // see 0 as -1, then find max subarray have sum 0
        // if sum[i] == sum[j], sum[i, j] == 0
        int sum = 0;
        int res = 0;
        unordered_map<int, int> s2i;
        s2i[0] = -1;
        for(int i = 0; i <nums.size(); i++){
            if(nums[i]==0) sum++;
            else sum--;
            // (l, r]
            if(s2i.count(sum)) res = max(res, i - s2i[sum]);
            else s2i[sum] = i;
        }
        return res;
    }
};