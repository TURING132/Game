#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int curPrefix = 1;
        int curPostfix = 1;
        for(int i = 0; i < nums.size(); i++){
            result[i] *= curPrefix;
            curPrefix *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0 ; i--){
            result[i] *= curPostfix;
            curPostfix *= nums[i];
        }
        return result;
    }
};

class Solution_On {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);
        vector<int> result(nums.size(), 0);
        int curPrefix = 1;
        int curPostfix = 1;
        for(int i = 0; i < nums.size(); i++){
            prefix[i] = curPrefix;
            curPrefix *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0 ; i--){
            postfix[i] = curPostfix;
            curPostfix *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            result[i] = prefix[i] * postfix[i];
        }
        return result;
    }
};

