#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> q;
    vector<bool> c, r, d, bd;
    vector<vector<string>> res;
    int n;
    bool dfs(int curC){
        if(curC == n){
            vector<string> r;
            for(int i = 0; i < n; i++){
                string s = "";
                for(int j = 0; j < n; j++){
                    s += q[i][j];
                }
                r.push_back(s);
            }
            res.push_back(r);
        }
        for(int i = 0; i < n; i++){
            if(!r[i] && !d[i + curC] && !bd[i - curC + n]){
                r[i] = true; d[i + curC] = true; bd[i - curC + n] = true;
                q[i][curC] = 'Q';
                if(dfs(curC + 1)){
                    return true;
                }
                r[i] = false; d[i + curC] = false; bd[i - curC + n] = false;
                q[i][curC] = '.';
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        q = vector<vector<char>>(n, vector<char>(n, '.'));
        c = vector<bool>(n, false);
        r = vector<bool>(n, false);
        d = vector<bool>(n*2, false);
        bd = vector<bool>(n*2, false);
        dfs(0);
        return res;
    }
};