#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> q;
    vector<bool> c, r, d, bd;
    vector<vector<string>> res;
    int n;
    void dfs(int curC){
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
                dfs(curC + 1);
                r[i] = false; d[i + curC] = false; bd[i - curC + n] = false;
                q[i][curC] = '.';
            }
        }
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