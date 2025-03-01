#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(!(x >= 0 && x < m && y >=0 && y < n))return 0;
        if(grid[x][y] == 0) return 0;
        int res = 1;
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            res += dfs(grid, x + dx[i], y  +dy[i]);
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j  <n; j++){
                if(grid[i][j]){
                    int s = dfs(grid, i, j);
                    res = max(s, res);
                }
            }
        }
        return res;
    }
};