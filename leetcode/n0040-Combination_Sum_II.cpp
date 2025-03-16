#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates, vector<bool>& visited, int startIndex, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i-1] && !visited[i-1])continue;
            if(target >= candidates[i]){
                visited[i] = true;
                path.push_back(candidates[i]);
                dfs(candidates, visited, i + 1, target - candidates[i]);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, visited, 0, target);  
        return res;
    }
};