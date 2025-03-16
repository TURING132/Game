#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<bool> c, r, d, bd;
    int res = 0;
    int n;
    void dfs(int curC){
        if(curC == n){
            res+=1;
            return;
        }
        for(int i = 0; i < n; i++){
            if(!r[i] && !d[i + curC] && !bd[i - curC + n]){
                r[i] = true; d[i + curC] = true; bd[i - curC + n] = true;
                dfs(curC + 1);
                r[i] = false; d[i + curC] = false; bd[i - curC + n] = false;
            }
        }
    }

    int totalNQueens(int n) {
        this->n = n;
        c = vector<bool>(n, false);
        r = vector<bool>(n, false);
        d = vector<bool>(n*2, false);
        bd = vector<bool>(n*2, false);
        dfs(0);
        return res;
    }
};