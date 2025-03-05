#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    vector<int> nums;
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        path = vector<int>(n, 0);
        st = vector<bool>(n, false);
        this->nums = nums;
        dfs(0);
        return res;
    }

    void dfs(int start){
        if(start == n){
            res.push_back(path);
            return;
        }
        unordered_set<int> set;
        for(int i = 0; i < n; i++){
            if(!st[i] && !set.count(nums[i])){
                path[start] = nums[i]; 
                set.insert(nums[i]);
                st[i] = true;
                dfs(start +1);
                st[i] = false;
            }
        }
    }
};