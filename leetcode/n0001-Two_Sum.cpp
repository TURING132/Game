#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.count(target - nums[i])){
                res.push_back(i);
                res.push_back(hash[target - nums[i]]);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};