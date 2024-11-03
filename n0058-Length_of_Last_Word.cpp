#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;
        for(; i >= 0; i--){
            if(s[i] != ' ') break;
        }
        for(; i >= 0; i--){
            if(s[i] != ' ') length++;
            else break;
        }
        return length;
    }
};