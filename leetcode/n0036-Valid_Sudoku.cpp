#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){ // check each row and each column
            set<char> rowSet;
            set<char> colSet;
            for(int j = 0; j < cols; j++){
                if(board[i][j] != '.'){
                    if(rowSet.find(board[i][j]) != rowSet.end()){
                        cout << "err row" << i << "," << j << endl;
                        return false;
                    }
                    rowSet.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(colSet.find(board[j][i]) != colSet.end()){
                        cout << "err col" << i << "," << j << endl;
                        return false;
                    }
                    colSet.insert(board[j][i]);
                }
            }
        }
        // check each 3*3 block
        for(int i = 0; i < rows; i+=3) {
            for(int j = 0; j < cols; j +=3) {
                set<char> blockSet;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++){
                        if(board[i + k][j + l] != '.'){
                            if(blockSet.find(board[i + k][j + l]) != blockSet.end()){
                                cout << "err block" << i << "," << j << endl;
                                return false; 
                                
                            }
                            blockSet.insert(board[i + k][j + l]);
                        }
                    }
                }
            }
        }
        return true;
    }
};