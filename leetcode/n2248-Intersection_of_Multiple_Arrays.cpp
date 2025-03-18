#include <vector>
#include <set>
using namespace std;

class Solution {
public:
// 统计每个元素出现次数会更快
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> res (nums[0].begin(), nums[0].end());
        for(int i = 1; i < nums.size(); i++){
            set<int> hash(nums[i].begin(), nums[i].end());
            set<int> newRes = res;
            for(auto & num : res){
                if(!hash.count(num))newRes.erase(num); 
            }
            res = newRes;
        }
        return vector(res.begin(), res.end());
    }
};