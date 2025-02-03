#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> indeg(n);
        for(int a = 0; a < n; a++){
            for(int & b : graph[a]){
                rg[b].push_back(a);
            }
            indeg[a] = graph[a].size();
        }

        queue <int> q;
        for(int i = 0; i < n; i++)
            if(indeg[i] == 0)
                q.push(i);

        while(q.size()){
            int a = q.front();
            q.pop();
            for(int & b : rg[a]){
                indeg[b]--;
                if(indeg[b] == 0)
                   q.push(b);
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};