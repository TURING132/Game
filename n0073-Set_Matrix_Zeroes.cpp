#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> zeroRow(m);
        vector<bool> zeroCol(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j]==0) {
                    zeroRow[i] = true;
                    zeroCol[j] = true;                 
                }
            }
        }  
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(zeroRow[i] || zeroCol[j]) {
                    matrix[i][j] = 0;                 
                }
            }
        }      
    }
};