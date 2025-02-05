#include <vector>
using namespace std;

class Solution {
public:
    int dir1[4] = {1, -1, 0, 0};
    int dir2[4] = {0, 0, 1, -1};
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j] != 'O') return;
        board[i][j] = 'A';
        for(int k =0; k <4; k++){
            int newi = i + dir1[k], newj = j + dir2[k];
            if(newi >=0 && newi < m && newj >=0 && newj < n){
                dfs(board, newi, newj);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1)&&board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};