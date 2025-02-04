#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}