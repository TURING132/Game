#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> nums;
    void dfs(int start, vector<bool>& used){
        res.push_back(path);
        for(int i = start; i < nums.size();i++){
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过，说明在路径上没有使用过，那么他会在另一条路径上被使用
            // 比如122，会出现12，12. 第二个12只在第一个2没有被用到的时候会出来
            // 只要第一个2出现过了，第二个2就可以用
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue; 
            path.push_back(nums[i]);
            used[i] = true;
            dfs(i+1, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size());
        sort(nums.begin(), nums.end());
        this->nums = nums;
        dfs(0, used);
        return res;
    }
};