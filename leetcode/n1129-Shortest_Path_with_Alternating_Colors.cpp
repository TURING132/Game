#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 这图的关键是需要做两种bfs，分别是最后一条边为红色，和最后一条边为蓝色
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        // 0 -> red, 1 - > blue
        for(auto & e : redEdges) next[0][e[0]].push_back(e[1]);
        for(auto & e : blueEdges) next[1][e[0]].push_back(e[1]);

        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        queue<pair<int ,int>> q;
        dis[0][0] = 0;
        dis[1][0] = 0;
        q.push({0, 0}); // (node, color)
        q.push({0, 1});
        while(!q.empty()){
            auto [a, c] = q.front(); q.pop();
            for(int b : next[1 - c][a]){
                if(dis[1-c][b] != INT_MAX) continue;;
                dis[1-c][b] = dis[c][a] + 1;
                q.push({b, 1-c});
            }
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = min(dis[0][i], dis[1][i]);
            if(res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};