#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> st;
    vector<int> p;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        p = vector<int>(n, 0);
        st = vector<bool>(n, false);
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int c){
        if(c == n){
            res.push_back(p);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!st[i]){
                p[c] = nums[i];
                st[i] = true;
                dfs(nums, c+1);
                st[i] = false;
            }
        }
    }

};