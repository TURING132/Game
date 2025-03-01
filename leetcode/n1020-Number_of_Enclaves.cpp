#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            res += dfs(grid, nx, ny);
        }
        return res;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // 先遍历四周，再遍历中间
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][n-1] == 1) dfs(grid, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[m-1][j] == 1) dfs(grid, m-1, j);
        }
        int res = 0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (grid[i][j] == 1) {
                    res += dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};