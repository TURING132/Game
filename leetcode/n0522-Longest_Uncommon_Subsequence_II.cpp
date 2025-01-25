#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubStr(string & s, string & t){
        if(s.size() < t.size()) return false;
        // found t in s, len(t) <= len(s)
        int ps = 0;
        bool found = false;
        for(int i = 0; i < t.size(); i++){
            found = false;
            while(ps < s.size() && t[i] != s[ps]) ps++;
            if(ps < s.size() && t[i] == s[ps]){
                found = true;
                ps ++;
            }
            if(!found) return false;
        }
        return true;
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string &a, const string & b){return a.size() > b.size();});
        for(int i = 0; i < strs.size(); i++){
            bool unique = true;
            for(int j = 0; j < strs.size(); j++){
                if(i == j) continue;
                if(isSubStr(strs[j], strs[i])){
                    unique = false;
                }
            }
            if(unique) return strs[i].size();
        }
        return -1;
    }
};