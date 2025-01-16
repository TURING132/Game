#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int beg = 0, end = 0; // [beg, end]
        while(beg < s.size()){
            end = min(int(s.size()-1), beg + k - 1);
            int l = beg, r = end;
            while(r > l) swap(s[l++], s[r--]);
            beg = min(int(s.size()), end + k + 1);
        }
        return s;
    }
};