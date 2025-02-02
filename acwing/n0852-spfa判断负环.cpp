#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int e[N], ne[N], h[N], w[N], idx = 0;
int m, n;
int cnt[N], dis[N];
bool st[N] = {false};
void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool spfa(){
    queue<int> q;
    for(int i = 1; i <=n; i++){
        q.push(i);
        st[i] = true;
    }

    while(q.size()){
        int a = q.front(); q.pop();
        st[a] = false;
        for(int i = h[a]; i != -1; i = ne[i]){
            int b = e[i];
            if(dis[b] > dis[a] + w[i]){
                dis[b] = dis[a] + w[i];
                cnt[b] = cnt[a] + 1;
                if(cnt[b] >= n) return true;
                if(!st[b]){
                    q.push(b);
                    st[b] = true;
                }
            }
        }
    }

    return false;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int _ = 0; _ < m; _++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if(spfa()) printf("Yes");
    else printf("No");
    return 0;
}