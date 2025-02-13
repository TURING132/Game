#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // f[j] = min(f[i-1] + cost[i-1], f[i - 2] + cost[i-2]);
        int n  = cost.size();
        vector<int>f(n+1, 0);
        for(int i = 2; i <= n; i++){
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
        }
        return f[n];
    }
};