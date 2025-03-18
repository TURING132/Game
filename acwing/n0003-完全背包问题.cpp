#include <iostream>
using namespace std;
const int N = 1010;
int w[N], f[N], v[N], n, m;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)scanf("%d%d", &v[i], &w[i]);
    for(int i = 0; i < n; i++){
        for(int j = v[i]; j <= m; j++){
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    printf("%d", f[m]);
    return 0;
}