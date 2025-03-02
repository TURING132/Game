#include <vector>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n + 1);
        for(vector<int> & p : paths){
            int a = p[0], b = p[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> res(n);
        for(int i = 1; i <= n; i++){
            vector<bool> color(5, false);
            for(int & b : adj[i]){
                color[res[b-1]] = true;
            }
            for(int j = 1; j <= 4; j++){
                if(!color[j]) {
                    res[i-1] = j;
                    break;
                }
            }
        }
        return res;
    }
};