#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> split(const string& s, char delim)  {
        // may have a empty string at first or last
        vector<string> res;
        string cur;
        for(const char & c : s){
            if(c == delim){
                res.push_back(move(cur));
            }else{
                cur += c;
            }
        }
        res.push_back(cur);
        return res;
    }

    string simplifyPath(string path) {
        vector <string> tokens = split(path, '/');
        cout << tokens.size() << endl;
        for(string & s : tokens){
        }
        vector <string> stack;
        for(string & s : tokens){
            if(s == "..") {
                if (stack.size() > 0) {
                    stack.pop_back();
                }
            }else if(s != "." && s != "") {
                stack.push_back(s);
            }
        }
        string res = "";
        for (string & s : stack) {
            res += "/" + s;
        }
        if(res.size() == 0) res = "/";
        return res;
    }
};
