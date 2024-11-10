#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(end != 0) s[end++] = ' '; //space
            int start = end;
            while(i < s.size() && s[i] != ' '){ // word
                s[end++] = s[i++];  
            }
            reverse(s.begin() + start, s.begin() + end);
        }
        s.erase(s.begin() + end, s.end());
        return s;
    }
};