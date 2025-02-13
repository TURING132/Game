#include <iostream>
using namespace std;
const int N = 1010;
int v[N], w[N], s[N], f[N][N];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d%d", &v[i], &w[i], &s[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= s[i] &&  k*v[i] <= j; k++){
                f[i][j] = max(f[i][j], f[i-1][j - v[i]*k] + w[i]*k);
            }
            
    printf("%d", f[n][m]);
    
    return 0;
}