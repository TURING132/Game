#include <vector>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n+1, 0));
        for(auto & s : strs){
            int numZero = 0, numOne = 0;
            for(auto & c : s)if(c=='0')numZero++;
            numOne = s.size() - numZero;
            for(int i = m; i >= numZero; i--){
                for(int j = n; j >= numOne; j--){
                    f[i][j] = max(f[i][j], f[i-numZero][j-numOne] + 1);
                }
            }
        }
        return f[m][n];
    }
};