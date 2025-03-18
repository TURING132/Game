#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto & num : nums){
            hash[num] ++;
            if(hash[num] > 2) return false;
        }
        return true;
    }
};