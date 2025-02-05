#include <iostream>
using namespace std;

int n;

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= (a/b) * x;
    return d;
}

int main(){
    scanf("%d", &n);
    int a, b, x, y;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}