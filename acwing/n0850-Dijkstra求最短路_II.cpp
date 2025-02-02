#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx = 0;
int dis[N];
int m, n;
bool st[N] = {false};

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dijkstra(){
    memset(dis, 0x3f, sizeof dis);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); // dis, no
    dis[1] = 0;

    while(heap.size()){
        PII p = heap.top(); heap.pop();
        int distance = p.first, a = p.second;

        if(st[a]) continue;
        st[a] = true;

        for(int i = h[a]; i != -1; i = ne[i]){
            int b = e[i];
            if(dis[b] > distance + w[i]){
                dis[b] = distance + w[i];
                heap.push({dis[b], b});
            }
        }
    }

    if (dis[n] == 0x3f3f3f3f) return -1;
    else return dis[n];
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int _ = 0; _ < m; _++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);
    }
    printf("%d", dijkstra());
    return 0;
}