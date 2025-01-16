#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int best;
    void update(int cur, int target){
        if(abs(cur - target) < abs(best - target)){
            best = cur;
        }
    }


    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        best = 1e9;
        for(int i =0; i < nums.size() - 2; i++) {
            int l = i+1;
            int r = nums.size()-1;
            while(l < r ) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return target;
                update(sum, target);
                if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return best;
    }
};