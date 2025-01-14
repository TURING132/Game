#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        int s = 0;
        unordered_map<int, int>r2c;
        r2c[0] = 1;
        for(int i = 0; i < nums.size();i++){
            s += nums[i];
            int re = (s%k+k)%k;// for negative
            if(r2c.count(re)){
                res += r2c[re];
            }
            r2c[re]++;
        }
        return res;
    }
};