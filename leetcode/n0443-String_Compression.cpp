#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0, l = 0, r = 0;
        while(r < chars.size()){ // [l, r)
            while(r < chars.size() && chars[l] == chars[r]) r++;
            chars[k++] = chars[l];
            int len = r - l;
            if(len > 1){
                int beg = k;
                while(len > 0){
                    chars[k++] = '0' + len%10;
                    len/=10;
                }
                reverse(&chars[beg], &chars[k]);
            } 
            l = r;
        }
        return k;
    }
};