#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = N;
int m, n;
int h[N], e[M], ne[M], idx = 0;
bool st[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int bfs(){
    int dis = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int size = q.size();
        for(int _ = 0; _ < size; _++){
            int a = q.front(); q.pop();
            if(a == n) return dis;
            for(int i = h[a]; i != -1; i = ne[i]){
                int b = e[i];
                if(st[b]) continue;
                st[b] = true;
                q.push(b);
            }
        }
        dis++;
    }
    return -1;
}

int main(){
    memset(st, false, sizeof st);
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d", bfs());
    return 0;
}