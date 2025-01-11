#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> mul(vector<int> &a, int b){
        vector<int>c;
        int t = 0;
        for(int i = 0; i < a.size(); i++){
            t+=a[i] * b;
            c.push_back(t%10);
            t/=10;
        }
        if(t)c.push_back(t);
        while(c.size()>1 && c.back()==0)c.pop_back();
        return c;
    }

    vector<int> add (vector<int> a, vector<int> b) {
        vector<int>c;
        if(a.size()<b.size())swap(a, b);
        int t = 0;
        for(int i = 0; i <a.size(); i++){
            t+=a[i];
            if(i < b.size())t+=b[i];
            c.push_back(t%10);
            t/=10;
        }
        if(t)c.push_back(t);
        return c;
    }

    string multiply(string num1, string num2) {
        vector<int> a, b;
        for(int i = num1.size()- 1; i >=0; i--)a.push_back(num1[i] - '0');
        for(int i = num2.size()- 1; i >=0; i--)b.push_back(num2[i] - '0');
        vector<int> res = {0};
        for(int i = 0; i < b.size(); i++){
            int t = b[i];
            vector<int> c = mul(a, t);
            c.insert(c.begin(), i, 0); // add 0
            res = add(c, res);
        }
        while(res.size()>1&&res.back()==0)res.pop_back(); // 0 * 52 = 00
        string r = "";
        for(int i = res.size()-1; i>=0; i--) r.push_back(res[i]+'0');
        return r;
    }
};