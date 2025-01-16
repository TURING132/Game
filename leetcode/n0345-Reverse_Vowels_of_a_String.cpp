#include <string>
using namespace std;
class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'A' 
            || c == 'e' || c == 'E'
            || c == 'i' || c == 'I'
            || c == 'o' || c == 'O'
            || c == 'u' || c == 'U') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            while(l < r && !isVowel(s[l])) l++;
            while(l < r && !isVowel(s[r])) r--;
            if(l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};