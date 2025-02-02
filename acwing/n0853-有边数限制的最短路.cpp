#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 100010;
int n, m, k, dis[N], backup[N];

struct Edge{
    int a, b ,w;
} edges[M];

int bellman_ford(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for(int _ = 0; _ < k; _ ++){
        memcpy(backup, dis, sizeof dis);
        for(int i = 0; i < m; i++){
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }

    if(dis[n] > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
    else return dis[n];
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int res = bellman_ford();
    if(res == 0x3f3f3f3f) printf("impossible");
    else printf("%d", res);
    return 0;
}