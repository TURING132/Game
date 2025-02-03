#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int m, n;
int h[N], e[M], ne[M], idx = 0;
int color[N]; // -1 没染色， 0 白色， 1 黑色

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool dfs(int u, int c){ // 当前节点， 颜色
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int b = e[i];
        if(color[b] == -1){
            if(!dfs(b, !c)) return false;
        }else if(color[b] == c){
            return false;
        }
    }
    return true;
}


bool check(){
    memset(color, -1, sizeof color);

    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(i, 0)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    if(check()) printf("Yes");
    else printf("No");
    
    return 0;
}