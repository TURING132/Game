#include <iostream>

const int N = 510;
int a[N][N], f[N][N];
int n;
using namespace std;
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            f[i][j] = max(f[i+1][j], f[i+1][j+1]) + a[i][j];
        }
    }
    printf("%d", f[1][1]);
    return 0;
}
