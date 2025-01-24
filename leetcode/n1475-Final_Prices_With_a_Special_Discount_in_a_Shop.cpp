#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        vector<int> stk;
        for(int i = prices.size()-1; i >= 0; i--){
            while(!stk.empty() && stk.back() > prices[i]) stk.pop_back();
            if(stk.empty()) res.push_back(prices[i]);
            else res.push_back(prices[i] - stk.back());
            stk.push_back(prices[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};