#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int k, n;
    void dfs(int cur){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = cur; i <= n; i++){
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        this->n = n;
        dfs(1);
        return res;
    }
};