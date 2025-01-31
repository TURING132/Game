#include <cstring>
#include <iostream>
using namespace std;

const int N = 10;
char p[N][N];
bool r[N], c[N], d[2*N], sed[2*N];
int n;

void dfs(int u){
    // 第u列放第几行
    if(u == n){
        for(int i = 0; i < n;i++){
            for(int j=0; j < n;j++){
                printf("%c", p[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        // 遍历每个可能的行
        if(!r[i] && !c[u] && !d[i+u] && !sed[n + u - i]){
            r[i] = true, c[u] = true, d[i+u] = true, sed[n + u - i] = true;
            p[i][u] = 'Q';
            dfs(u+1);
            r[i] = false, c[u] = false, d[i+u] = false, sed[n + u - i] = false;
            p[i][u] = '.';
        }
    }
}

int main(){
    scanf("%d",&n);
    memset(p, '.', sizeof(p));
    dfs(0);
    return 0;
}