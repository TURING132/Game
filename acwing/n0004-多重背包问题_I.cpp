#include <iostream>
using namespace std;
const int N = 1010;
int s[N], v[N], w[N], f[N][N];
int n,m;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d%d", &v[i], &w[i], &s[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j  <= m; j++){
            for(int k = 0; k <= s[i] && j >= k * v[i]; k++){
                f[i][j] = max(f[i-1][j - k * v[i]] + k * w[i], f[i][j]);
            }
        }
    }
    printf("%d", f[n][m]);
    return 0;
}