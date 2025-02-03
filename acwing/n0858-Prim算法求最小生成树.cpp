#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        if(i != 0 && dist[t] == INF) return INF;
        if(i != 0) res += dist[t];
        st[t] = true;

        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}

int main(){
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for(int _ = 0; _ < m; _++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int res = prim();
    if(res == INF) printf("impossible");
    else printf("%d", res);
    return 0;
}