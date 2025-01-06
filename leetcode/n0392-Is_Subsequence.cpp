#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pt = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            bool found = false;
            while(pt < t.size()){
                if(c == t[pt++]){
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }   
        return true;     
    }
};