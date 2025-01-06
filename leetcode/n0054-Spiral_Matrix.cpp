#include <vector>
using namespace std;
#define EMPTY -999
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result(matrix.size() * matrix[0].size(), 0);
        int moves[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        int pos[2] = {0, -1};
        int move = 0;
        for(int i = 0; i < matrix.size() * matrix[0].size(); i++){
            int r = pos[0] + moves[move][0];
            int c = pos[1] + moves[move][1];
            if(r >= matrix.size() || r < 0 
                || c >= matrix[0].size() || c < 0
                || matrix[r][c] == EMPTY) {
                move = (move + 1) % 4;
                r = pos[0] + moves[move][0];
                c = pos[1] + moves[move][1];
            }
            result[i] = matrix[r][c];
            matrix[r][c] = EMPTY;
            pos[0] = r;
            pos[1] = c;
        }
        return result;
    }
};