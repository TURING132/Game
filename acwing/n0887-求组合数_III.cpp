#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, p;

int qmi(int a, int k){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a %p;
        a = (LL) a * a %p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b){
    int res = 1;
    for(int i = 1, j = a; i <= b; i++, j--){
        res = (LL) res * j %p;
        res = (LL) res * qmi(i, p-2) %p;
    }
    return res;
}

int lucas(LL a, LL b){
    if(a < p && b < p)return C(a, b);
    return (LL)C(a %p, b %p) * lucas(a / p, b / p) %p;
}

int main(){
    scanf("%d", &n);
    while(n--){
        LL a, b;
        scanf("%lld%lld%d", &a, &b, &p);
        printf("%d\n", lucas(a, b));
    }
    
    return 0;
}