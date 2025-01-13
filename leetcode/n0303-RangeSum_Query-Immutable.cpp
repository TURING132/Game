#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> s;
    NumArray(vector<int>& nums) {
        s.resize(nums.size()+1, 0); 
        for(int i = 1; i < s.size();i++){
            s[i] = s[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return s[right+1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */