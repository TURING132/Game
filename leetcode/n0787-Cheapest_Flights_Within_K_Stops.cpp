#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INF);
        vector<int> backup;
        dist[src] = 0;
        for(int i = 0; i < k; i++){
            backup = vector<int>(dist);
            for(int j = 0; j < flights.size(); j++){
                int a = flights[j][0], b = flights[j][1], c = flights[j][2];
                dist[b] = min(dist[b], backup[a] + c);                    
            }
        }
        if(dist[dst] > INF/2) return -1;
        else return dist[dst];

    }
};