#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int n;
LL exgcd(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
LL inline mod(LL a, LL b){
    return ((a % b) + b) % b;
}
int main(){
    scanf("%d", &n);
    LL a1, m1;
    scanf("%lld%lld", &a1, &m1);
    for(int i = 1; i < n; i++){
        LL a2, m2, k1, k2;
        scanf("%lld%lld", &a2, &m2);
        LL d = exgcd(a1, -a2, k1, k2);
        if((m2 - m1) % d){ puts("-1"); return 0; }
        k1 = mod(k1 * (m2 - m1) / d, abs(a2 / d));
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);
    }
    printf("%lld\n", m1);
    return 0;
}