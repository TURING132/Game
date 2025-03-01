#include <vector>
using namespace std;
class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.resize(n+1, 0);
        for(int i = 1; i <= n; i++){
            p[i] = i;
        }
        for(vector<int> & e : edges){
            int a = e[0], b = e[1];
            int pa = find(a), pb = find(b);
            if(pa != pb) p[pa] = p[pb];
            else return e;
        }
        return vector<int>{};
    }
};