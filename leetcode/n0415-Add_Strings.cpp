#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> a, b;
        for(int i = num1.size()-1; i>=0; i--) a.push_back(num1[i] - '0');
        for(int i = num2.size()-1; i>=0; i--) b.push_back(num2[i] - '0');
        string res = "";
        int t = 0;
        if(a.size() < b.size()) swap(a, b);
        for(int i = 0; i < a.size(); i++){
            t += a[i];
            if(i < b.size()) t+=b[i];
            res.push_back(t%10 + '0');
            t/=10;
        }
        if(t)res.push_back(t + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};