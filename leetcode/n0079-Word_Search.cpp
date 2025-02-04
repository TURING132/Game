#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>> & visited, 
        string & word, int i, int j, int c){
        if(word[c] != board[i][j]) return false;
        if(c == word.size() - 1) return true;
        visited[i][j] = true;
        int dir1[4] = {0, 0, 1, -1};
        int dir2[4] = {1, -1, 0, 0}; 
        for(int k = 0; k < 4; k++){
            int newi = i + dir1[k], newj = j + dir2[k];
            if(newi >=0 && newi < visited.size() && newj >=0 && newj < visited[0].size() && !visited[newi][newj]){
                if(dfs(board, visited, word, newi, newj, c+1)){
                    return true;
                }
            }
        }
        visited[i][j] = false; // recover state
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char c = word[0];
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board, visited, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};