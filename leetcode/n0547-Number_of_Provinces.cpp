#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            if (!visited.count(i)){
                res++;
                dfs(i, isConnected);
            }
        }
        return res;
    }

    void dfs(int i, vector<vector<int>>& isConnected){
        if(visited.count(i)) return;
        visited.insert(i);
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[i][j]) dfs(j, isConnected);
        }
    }
};