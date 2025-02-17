#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // f[1] = 1, f[2] = 2
        // f[i] = sum(f[j - 1]*f[i-j]) for j in [1, i]
        if(n == 1)return 1;
        vector<int> f(n+1, 0);
        f[1] = 1; f[0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                f[i] += f[j-1] * f[i-j];
            }
        }
        return f[n];
    }
};