#include <vector>
using namespace std;
typedef long long LL;
class Solution {
public:
    const int mod = 1337;

    int qmi(int a, int b){
        // a^b
        int t = a % mod, res = 1;
        while(b){
            if(b & 1) res = (LL)res * t % mod;
            t = (LL)t * t % mod;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1, t = a % mod;
        for(int i = b.size() - 1; i >= 0; i--){
            res = (LL) res * qmi(t, b[i]) % mod;
            t = (LL) qmi(t, 10) % mod;
        }
        return res;
    }
};