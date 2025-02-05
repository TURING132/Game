#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        int start = n, end = -1;
        for(int i = 0; i < n; i++){
            if(bank[i] == startGene) start = i;
            if(bank[i] == endGene) end = i;
        }
        if(start == n) {bank.push_back(startGene); n++;}
        vector<vector<int>> g(n , vector<int>(n, 0));
        // start -> end
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cnt = 0;
                for(int k = 0; k < bank[i].size(); k++){
                    if(bank[i][k] != bank[j][k]) {
                        cnt++;
                        if(cnt > 1) break;
                    }
                }
                if(cnt == 1){
                    g[i][j] = g[j][i] = 1;
                }
            }
        }
        // bfs
        queue<int> q;
        vector<int> st(n);
        int cnt = 0;
        q.push(start);
        st[start] = true;
        while(q.size()){
            int size = q.size();
            for(int _ = 0; _ < size; _++){
                int ne = q.front(); q.pop();
                if(ne == end) return cnt;
                for(int i = 0; i < n; i++){
                    if(g[ne][i] && !st[i]) {
                        st[i] = true;
                        q.push(i);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};