#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)return false;
        vector<int> s(nums.size()+1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            s[i] = s[i-1] + nums[i-1];
            if(i>1 && s[i]%k == 0) return true; // [1, i] %k == 0
        }
        // Congruence Theorem: s[i] == s[j]
        unordered_map<int, int> r2i;
        for(int i = 1; i < s.size();i++){
            int re = s[i] % k;
            if(r2i.count(re)){
                if(i - r2i[re] > 1)
                    return true;
            }
            else r2i[re] = i;
        }
        return false;
    }
};