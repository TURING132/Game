#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;
    bool dfs(int u, int c){
        color[u] = c;
        for(int & b : g[u]){
            if(color[b] == -1){
                if(!dfs(b, !c)){
                    return false;
                }
            }else if(color[b] == c) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // build graph
        g = vector<vector<int>>(n+1);
        color = vector<int>(n+1, -1);
        for(vector<int> & e : dislikes){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};