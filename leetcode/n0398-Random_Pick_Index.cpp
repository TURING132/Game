#include <unordered_map>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> pos;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            pos[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> & poss = pos[target];
        return poss[rand() % poss.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */