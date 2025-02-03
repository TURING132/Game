#include <vector>
using namespace std;
// -1 no color, 0 whit, 1 black
class Solution {
public:
    vector<int> color;

    bool dfs(vector<vector<int>>& g, int u, int c){
        color[u] = c;
        for(int & b : g[u]){
            if(color[b] == -1){
                if(!dfs(g, b, !c))
                    return false;
            }
            else if(color[b] == c)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!dfs(graph, i, 0))
                    return false;
            }
        }
        return true;
    }
};