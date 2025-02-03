#include <vector>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n+1, vector(n+1, INF));
        vector<int> dist(n+1, INF);
        vector<bool> st(n+1, false);
        for(vector<int> & e : times){
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = c;
        }
        dist[k] = 0;
        for(int i = 0; i < n-1; i++){
            int t = -1;
            for(int j = 1; j <= n; j++)
                if(!st[j] && (t == -1 || dist[j] < dist[t]))
                    t = j;
            st[t] = true;
            for(int j = 1; j <= n; j++){
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int res = -1;
        for(int i = 1; i <= n; i++) res = max(res, dist[i]);
        return res == INF ? -1 : res;
    }
};