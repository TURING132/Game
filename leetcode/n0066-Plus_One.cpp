#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t = 1;
        for(int i = digits.size() - 1; i >=0; i--){
            t+=digits[i];
            digits[i] = t%10;
            t /= 10;
            if(t == 0) break;
        }
        if(t)digits.insert(digits.begin(), t);
        return digits;
    }
};