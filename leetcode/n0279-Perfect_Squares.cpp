#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for(int i = 1; i * i <= n; i++){
            for(int j = i * i; j <= n; j++){ // 不用判断无解，因为i=1必定是一个解，后续可以保证
                f[j] = min(f[j], f[j - i*i] + 1);
            }
        }
        return f[n];
    }
};