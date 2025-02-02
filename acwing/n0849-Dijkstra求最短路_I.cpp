#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N] = {0};
int dis[N];
bool st[N] = {false};
int m, n;

int dijstra(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for(int _ = 0; _ < n; _++){
        int t = -1;
        for(int i = 1; i <= n; i++)
            if(!st[i] && (t==-1||dis[i] < dis[t]))
                t = i;
        for(int i = 1; i <= n; i++)
            dis[i] = min(dis[i], dis[t] + g[t][i]);
        st[t] = true;
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    else return dis[n];
}

int main(){
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for(int _=0; _ < m; _++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    printf("%d", dijstra());
    return 0;
}