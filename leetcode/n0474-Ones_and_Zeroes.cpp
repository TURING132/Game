#include <vector>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // f[i, j] 表示最多有 i 个 0， j 个 1的字符串子集大小
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for(string & s : strs){
            int numZero = 0, numOne = 0;
            for(char c : s) if(c == '0') numZero++; else numOne++;
            for(int i = m; i >= numZero; i--){
                for(int j = n; j >= numOne; j--){
                    f[i][j] = max(f[i][j], f[i - numZero][j - numOne] + 1);
                }
            }
        }
        return f[m][n];
    }
};