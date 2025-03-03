#include <vector>
using namespace std;
class Solution {
public:
    int a[4] = {0, 1, 0, -1};
    int b[4] = {1, 0, -1, 0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n));
        int dir = 0;
        int x = 0, y = -1;
        for(int i = 1; i <= n * n; i++){
            int nx = x + a[dir];
            int ny = y + b[dir];
            while(!(nx >= 0 && nx < n && ny >= 0 && ny < n && res[nx][ny] == 0)){
                dir = (dir + 1) % 4;
                nx = x + a[dir];
                ny = y + b[dir];
            }
            x = nx, y = ny;
            res[x][y] = i;
        }
        return res;
    }
};