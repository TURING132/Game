#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> p;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(graph, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, int u){
        p.push_back(u);
        if(u == n - 1) {res.push_back(p); p.pop_back(); return;}
        for(int & b : graph[u]){
            dfs(graph, b);
        }
        p.pop_back();
    }
};