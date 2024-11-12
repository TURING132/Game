#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int l = 0; l < nums.size(); l++){
            if(l > 0 && nums[l] == nums[l - 1]) continue;
            if(nums[l] > 0) break;
            int m = l + 1, r = nums.size() - 1;
            while(m < r){
                if(m != l + 1 && nums[m] == nums[m - 1]){
                    m++;
                    continue;
                }
                if(nums[l] + nums[m] + nums[r] < 0){
                    m++;
                }else if(nums[l] + nums[m] + nums[r] > 0){
                    r--;
                }else{
                    res.push_back({nums[l], nums[m], nums[r]});
                    m++;
                    r--;
                }
            }
            
        }   
        return res;     
    }
};

int main() {
    vector<int> test = {0, 0, 0, 0};
    Solution solution;
    solution.threeSum(test);

    return 0;
}