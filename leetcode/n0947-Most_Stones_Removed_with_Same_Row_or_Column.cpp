#include <vector>
using namespace std;

class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x]; 
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        p = vector<int>(n);
        for(int i = 0; i < n; i++) p[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0]
                    || stones[i][1] == stones[j][1]){
                        p[find(i)] = find(j);
                    }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == i) cnt++;
        }
        return n - cnt;
    }
};