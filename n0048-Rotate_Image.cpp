#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int d = 0; d < n / 2 ; d++){
            for(int i = 0; i < n - 2*d - 1; i++){
                int temp = matrix[d][d+i];
                matrix[d][d+i] = matrix[n-1-d-i][d];
                matrix[n-1-d-i][d] = matrix[n-1-d][n-1-d-i];
                matrix[n-1-d][n-1-d-i] = matrix[d+i][n-1-d];
                matrix[d+i][n-1-d] = temp;
            }
        }
    }
};