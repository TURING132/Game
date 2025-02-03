#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx; // 只储存左到右的边
int match[N]; // 左边匹配上了右边哪个
bool st[N]; // 右边是否访问过了

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int b = e[i];
        if(!st[b]){
            st[b] = true;
            if(match[b] == 0 || find(match[b])){
                match[b] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for(int i = 1; i<=n1; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    printf("%d", res);

    return 0;
}