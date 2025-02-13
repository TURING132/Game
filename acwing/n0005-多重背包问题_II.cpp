#include <iostream>
using namespace std;
const int N = 25000, M = 2010;
int v[N], w[N],  f[M];
int n, m;
int cnt = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);
        int k = 1;
        while(k <= s){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k*=2;
        }
        if(s > 0) {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
        
    }
    n = cnt;
    
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
            
    printf("%d", f[m]);
    
    return 0;
}