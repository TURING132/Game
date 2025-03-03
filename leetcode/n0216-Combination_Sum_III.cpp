#include <vector>
using namespace std;

class Solution {
public:
    int k;
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;

    void dfs(int curNum, int target){
        if(path.size() == k){
            if(target == 0)res.push_back(path);
            return;
        }
        for(int i = curNum; i <= 9 && !st[i]; i++){
            path.push_back(i);
            st[i] = true;
            dfs(curNum + 1, target - i);
            path.pop_back();
            st[i] = false;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        st.resize(10, false);
        this->k = k;
        dfs(1, n);
        return res;
    }
};