#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(5));
        f[0][1] = -prices[0];
        f[0][3] = -prices[0]; // 关键一步，保证考虑了进行一次和进行两次交易的结果
        for(int i = 1; i < prices.size(); i++){
            f[i][0] = f[i-1][0];
            f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i]);
            f[i][2] = max(f[i-1][2], f[i-1][1] + prices[i]);
            f[i][3] = max(f[i-1][3], f[i-1][2] - prices[i]);
            f[i][4] = max(f[i-1][4], f[i-1][3] + prices[i]);
        }
        return f[n-1][4];
    }
};