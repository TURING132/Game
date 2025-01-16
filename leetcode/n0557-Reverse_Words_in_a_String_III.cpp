#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int beg = 0, end = 0; // [beg, end)
        while(end < s.size()){
            while(end < s.size() && s[end] != ' ') end++;
            int l = beg, r = end - 1;
            while(l < r) swap(s[l++], s[r--]); 
            beg = end + 1;
            end = beg;
        }
        return s;
    }
};