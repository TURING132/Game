#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> s(nums.size()+1, 0);
        for(int i = 1; i < s.size(); i++){
            s[i] = s[i-1] + nums[i-1];
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == s.back() - s[i]) return i -1;
        }
        return -1;
    }
};