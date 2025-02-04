#include <iostream>
using namespace std;

int n;

void divide(int x){
    for(int i = 2; i <= x/i; i++){
        int exp = 0;
        while(x%i == 0){
            exp++;
            x/=i;
        }
        if(exp>0) printf("%d %d\n", i, exp);
    }
    if(x > 1) printf("%d 1\n", x);
    printf("\n");
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        divide(x);
    }
    return 0;
}