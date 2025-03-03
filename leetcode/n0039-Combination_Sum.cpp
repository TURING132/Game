#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void dfs(vector<int>& candidates, int curindex, int target){
        if(target == 0) {
            res.push_back(path);
            return;
        }else if(target < 0) return;
        for(int i = curindex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }
};