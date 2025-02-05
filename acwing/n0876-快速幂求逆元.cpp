#include <iostream>
typedef long long LL;
using namespace std;
int n;

int qmi(int a, int b, int p){
    int res = 1, t = a;
    while(b>0){
        if(b & 1) res  = (LL) res * t % p;
        t = (LL) t * t %p;
        b = b>>1;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, p;
        scanf("%d%d", &a, &p);
        if(a % p == 0) printf("impossible\n");
        else printf("%d\n", qmi(a, p-2 , p));
    }
}