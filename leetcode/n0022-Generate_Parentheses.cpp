#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int n;
    vector<string> res;
    string cur;
    vector<string> generateParenthesis(int n) {
        this->n = n;
        cur.resize(2*n);
        dfs(0, 0);
        return res;
    }

    void dfs(int c, int l){
        // number of left
        int r = c - l;
        if(c == 2 * n) { res.push_back(cur); return;}
        if(l > r){
            if(l < n){
                cur[c] = '(';
                dfs(c + 1, l + 1);
            }
            if(r < n){
                cur[c] = ')';
                dfs(c + 1, l);
            }
        }else{
            if(r < n){
                cur[c] = cur[c] = '(';
                dfs(c + 1, l + 1);
            }
        }
    }

};