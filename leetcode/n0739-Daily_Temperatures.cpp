#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        vector<pair<int, int>> stk; // (val, index)
        for(int i = temperatures.size()-1; i>=0; i--){
            while(!stk.empty() && stk.back().first <= temperatures[i]){
                stk.pop_back();
            }
            if(stk.empty()) res.push_back(0);
            else res.push_back(stk.back().second - i);
            stk.push_back({temperatures[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};