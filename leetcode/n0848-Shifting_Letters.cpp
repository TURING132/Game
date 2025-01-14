#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long> sum(shifts.size()+1, 0);
        for(int i = s.size() - 1; i >= 0 ; i--){
            sum[i] = sum[i+1] + shifts[i];
        }
        for(int i = 0; i < s.size(); i++){
            s[i] = 'a' + ((s[i] - 'a') + sum[i]) % 26;
        }
        return s;
    }
};