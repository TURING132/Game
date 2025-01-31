#include <iostream>

using namespace std;
const int N = 10;
int p[N] = {0};
bool st[N] = {false};
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++)printf("%d", p[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            p[u] = i;
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}