#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> path;
    string s;
    void dfs(int start){
        // [start, end)
        int n = s.size();
        if(path.size() == 3){
            string seg = s.substr(start, n - start);
            if(valid(seg)){
                string ss = "";
                for(string & s : path) ss +=s + ".";
                ss += seg;
                res.push_back(ss);
            }
            return;
        }
        for(int i = start+1; i <= n; i++){
            string seg = s.substr(start, i - start);
            if(!valid(seg)) continue;
            path.push_back(seg);
            dfs(i);
            path.pop_back();
        }
    }

    bool valid(const string & s){
        int n = s.size();
        if(n > 3 || n <= 0)return false;
        if(n > 1 && s[0] == '0') return false;
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            num *= 10;
            num += s[i] - '0';
        }
        return num <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        dfs(0);
        return res;
    }
};