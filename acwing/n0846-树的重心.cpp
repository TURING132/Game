#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int ans = N;

// 返回u为根的子树中节点的数量
int dfs(int u){
    st[u] = true;
    int sum = 1, res = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        int c = dfs(j);
        res = max(c, res);
        sum += c;
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}


int main(){
    memset(h, -1, sizeof h);
    // memset(st, false, sizeof st);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}