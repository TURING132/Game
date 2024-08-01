#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int beg = 0;
        int result = INT_MAX;
        // [beg, end]
        for(int end = 0; end < nums.size(); end++){
            sum += nums[end];
            while(sum >= target){
                result = result < end - beg + 1 ? result : end - beg + 1;
                sum -= nums[beg];
                beg ++;
            }
        }
        if(result == INT_MAX) result = 0;
        return result;
    }
};

int main(){
    Solution solution;
    int target = 7;
    vector<int> vec = {2,3,1,2,4,3};
    printf("%d", solution.minSubArrayLen(target, vec));
    return 0;
}