#include <iostream>
using namespace std;
const int N = 15000, M = 2010;
int f[M], v[N], w[N], n, m, cnt;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);
        int k = 1;
        while(k <= s){
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
            cnt++;
        }
        if(s){
            v[cnt] = a * s;
            w[cnt] = b * s;
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++){
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[m]);
    return 0;
}