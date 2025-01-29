#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> n2c;
        for(int & n : nums) n2c[n]++;
        vector<int>res;
        int n = nums.size() / 3;
        for(pair<int, int> p  : n2c){
            if(p.second > n){
                res.push_back(p.first);
            }
        }
        return res;
    }
};