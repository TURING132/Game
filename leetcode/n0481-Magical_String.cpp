#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;
        string s = "122";
        int res = 1;
        bool one = true;
        for(int i = 2; i < n; i++){
            if(one){
                for(int j = 0; j < s[i] - '0'; j++) s += "1";
                one = !one;
            }else{
                for(int j = 0; j < s[i] - '0'; j++) s += "2";
                one = !one;
            }
            if(s[i] == '1') res ++;
        }
        cout << s << endl;
        return res;
    }
};