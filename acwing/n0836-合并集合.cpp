#include <iostream>
using namespace std;
const int N = 100010;
int p[N] = {0};
int m, n;

int find(int x){ // find的同时会进行压缩，每个节点会指向根节点
    // 压缩完毕
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b){
    p[find(a)] = find(b);
}

bool query(int a, int b){
    return find(a) == find(b);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <=n; i++){
        p[i] = i;
    }
    for(int _ = 0; _ < m; _++){
        char op[2];
        int a, b;
        scanf("%s", op);
        scanf("%d%d", &a, &b);
        if(op[0] == 'M') {
            merge(a, b);
        }else{
            if(query(a, b)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;    
}
