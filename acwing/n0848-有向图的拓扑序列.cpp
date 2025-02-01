#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010, M = N;
int m, n;
int h[N], e[M], ne[M], idx = 0;
int d[N], res[N], ridx = 0;


void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool topSort(){
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(d[i] == 0) {q.push(i); cnt++; res[ridx++] = i;}

    while(!q.empty()){
        int a = q.front(); q.pop();
        for(int i = h[a]; i != -1; i = ne[i]){
            int b = e[i];
            d[b] --;
            if(d[b] == 0){
                q.push(b);
                cnt ++;
                res[ridx++] = b;
            }
        }
    }
    return cnt == n;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    if(topSort()){
        for(int i = 0; i < n; i++){
            printf("%d ", res[i]);
        }
    }else{
        printf("-1");
    }
    return 0;
}