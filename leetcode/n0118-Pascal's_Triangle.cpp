#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(1, vector<int>(1,1));
        for(int i = 1; i < numRows; i++){// 遍历每一行
            vector<int> newRow(i + 1);
            newRow[0] = 1; newRow[i] = 1;
            for(int j = 1; j < i; j++){
                newRow[j] = res[i-1][j] + res[i-1][j-1];
            }
            res.push_back(newRow);
        }
        return res;
    }
};