#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int right = 0;
        int end = 0;
        int step = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            right = max(i + nums[i], right);
            if(i >= end){
                step++;
                end = right;
            }
        }
        return step;
    }
};