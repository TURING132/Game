#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> nums;
    void dfs(int start){
        if(path.size()>=2)res.push_back(path);
        unordered_set<int> uset; 
        for(int i = start; i < nums.size();i++){
            if(path.size() && nums[i] < path.back() || uset.count(nums[i])) continue;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            dfs(i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        dfs(0);
        return res;
    }
};