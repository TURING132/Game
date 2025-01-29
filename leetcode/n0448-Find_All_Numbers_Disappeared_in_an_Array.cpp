#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = (nums[i]-1)%n;
            if (nums[x] <= n) nums[x] += n;
        }
        vector<int> res;
        for(int i =0; i < n; i++){
            if(nums[i] <= n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};