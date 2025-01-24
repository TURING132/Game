#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for(int i = 0; i < num.size(); i++){
            while(k > 0 && !stk.empty() && stk.back() > num[i]) {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        for(; k > 0; k--){
            stk.pop_back();
        }

        string res = "";
        int i = 0;
        while(i < stk.size() && stk[i] == '0') i++;
        for(; i < stk.size(); i++) res += stk[i];
        return res == "" ? "0" : res;
    }
};