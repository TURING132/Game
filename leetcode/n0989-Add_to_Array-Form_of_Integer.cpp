#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        vector<int> b;
        while(k>0){
            b.push_back(k%10);
            k/=10;
        }
        vector<int> c;
        int t = 0;
        if(num.size() < b.size()) swap(num, b);
        for(int i = 0 ; i < num.size(); i++) {
            t += num[i];
            if(i < b.size()) t+= b[i];
            c.push_back(t%10);          
            t/=10;
        }
        if(t) c.push_back(t);
        reverse(c.begin(), c.end());
        return c;
    }
};