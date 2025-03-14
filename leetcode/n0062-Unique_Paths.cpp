#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // f[i][j] = f[i-1][j] + f[i][j-1]
        vector<int>f(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                f[j] = f[j] + f[j-1];
        }
        return f[n-1];
    }
};


// #include <vector>
// using namespace std;
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         // f[i][j] = f[i-1][j] + f[i][j-1]
//         vector<vector<int>>f(m, vector<int>(n, 0));
//         for(int i = 0; i < m; i++)f[i][0] = 1;
//         for(int i = 0; i < n; i++)f[0][i] = 1;
//         for(int i = 1; i < m; i++)
//             for(int j = 1; j < n; j++)
//                 f[i][j] = f[i-1][j] + f[i][j-1];
//         return f[m-1][n-1];
//     }
// };