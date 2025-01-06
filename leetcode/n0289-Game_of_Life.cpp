#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0 -> now died next died 1 -> now live next live 
        // 2 -> now died next live 3 -> now live next died
        int next[3] = {0, 1, -1 };
        int rows = board.size();
        int cols = board[0].size();
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                int liveCount = 0;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(i == 0 && j == 0) {
                            continue;
                        }
                        int row = r + next[i];
                        int col = c + next[j];
                        if(row >= 0 && row < rows && col >=0 && col < cols 
                            && (board[row][col] == 1 || board[row][col] == 3)) {
                                liveCount ++;
                            }
                    }
                }
                if(board[r][c] == 1){
                    if (liveCount < 2 || liveCount > 3) {
                        board[r][c] = 3;
                    }
                }else{
                    if (liveCount == 3){
                        board[r][c] = 2;
                    }
                }
            }
        }
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 2){
                    board[r][c] = 1;
                }
                if(board[r][c] == 3){
                    board[r][c] = 0;
                }
            }
        }
    
    }
};