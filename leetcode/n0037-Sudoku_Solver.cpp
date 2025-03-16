#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> cols; // 储存每一列的9个数字是否使用过
    vector<vector<bool>> block; // 储存每个block的数字是否使用过
    vector<vector<bool>> rows; // 储存每一行的每9个数字是否使用过
    vector<pair<int, int>> spaces;

    int xy2block(int x, int y){
        // return 0 ~ 8
        int res = x / 3;
        res += 3 * (y / 3);
        return res;
    }

    bool dfs(vector<vector<char>>& board, int cur){ // 按照行进行深搜
        if(cur >= spaces.size()) return true;
        auto [x, y] = spaces[cur];
        for(int num = 0; num < 9; num ++){
            if(!cols[y][num] && !rows[x][num] && !block[xy2block(x, y)][num]){
                board[x][y] = '1' + num;
                cols[y][num] = true;
                rows[x][num] = true;
                block[xy2block(x, y)][num]=  true;

                if(dfs(board, cur + 1)) return true;

                board[x][y] = '.';
                cols[y][num] = false;
                rows[x][num] = false;
                block[xy2block(x, y)][num]=  false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        cols = vector(9, vector<bool>(9, false));
        rows = vector(9, vector<bool>(9, false));
        block = vector(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j ++){
                int val = board[i][j];
                if(val == '.') {
                    spaces.push_back({i, j});
                    continue;
                }

                rows[i][val - '1'] = true;
                cols[j][val - '1'] = true;
                block[xy2block(i, j)][val - '1'] = true;
            }
        }
        dfs(board, 0);
    }
};