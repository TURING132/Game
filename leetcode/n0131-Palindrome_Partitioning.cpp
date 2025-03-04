#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    string s;
    void dfs(int start){
        int n = s.size();
        if(start >= n){
            res.push_back(path);
            return;
        }
        for(int i = start + 1; i <= n; i++){
            // [start, i)
            string seg = s.substr(start, i - start);
            if(!valid(seg)) continue;
            path.push_back(seg);
            dfs(i);
            path.pop_back();
        }
    }

    bool valid(const string & s){
        int pa = 0, pb = s.size()-1;
        while(pa < pb){
            if(s[pa++] != s[pb--]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        this->s = s;
        dfs(0);
        return res;
    }
};