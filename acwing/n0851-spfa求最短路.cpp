#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int e[N], w[N], h[N], ne[N], idx = 0;
int dis[N];
int m, n;
bool st[N] = {false};

void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int spfa(){
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    st[1] = true;
    while(q.size()){
        int a = q.front(); q.pop();
        st[a] = false;
        for(int i = h[a]; i != -1; i = ne[i]){
            int b = e[i];
            if(dis[b] > dis[a] + w[i]) {
                dis[b] = dis[a] + w[i];
                if(!st[b]){
                    q.push(b);
                    st[b] = true;
                }
            }
        }
    }
    return dis[n];
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int _ = 0; _ < m; _++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int res = spfa();
    if(res == 0x3f3f3f3f) printf("impossible");
    else printf("%d", res);
    return 0;
}