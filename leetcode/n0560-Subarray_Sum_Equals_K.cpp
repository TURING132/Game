#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // vector<int> s(nums.size()+1, 0);
        // for(int i = 1; i <= nums.size();i++){
        //     s[i] = s[i-1] + nums[i-1];
        // }
        // int res = 0;
        // for(int i = 1; i < s.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j < s.size(); j++){
        //         if(s[j] - s[i-1] == k) res++;
        //     }
        // }
        // return res;

        // i <= j
        // s[j] - s[i] == k <=> s[i] = s[j] - k
        // hsa a hash map to store (sum, count)
        unordered_map<int, int> s2c;
        s2c[0] = 1; // if s[j] == k, satisfy
        int res = 0;
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
            if(s2c.count(s - k)) {
                res += s2c[s-k];
            }
            s2c[s]++;
        }
        return res;
    }
};