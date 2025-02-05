#include <iostream>
using namespace std;

int n;

typedef long long LL;

int qmi(int a, int b, int p){
    int res = 1, t = a;
    while(b > 0){
        if(b&1) res  = (LL)res * t %p;
        t = (LL)t * t %p;
        b  =  b>> 1;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    int a, b, p;
    for(int _ = 0 ; _ < n; _++){
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", qmi(a, b, p));
    }

}