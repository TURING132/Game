#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {0};
        bool count[26] = {false};
        for(int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;

        string stk;
        for(int i = 0; i < s.size(); i++){
            if(count[s[i] - 'a']) continue;
            while(!stk.empty() && last[stk.back() - 'a'] > i && stk.back() > s[i]){ 
                count[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            count[s[i]-'a'] = true;
        }
        return stk;
    }
};