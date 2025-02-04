#include <iostream>
using namespace std;

int n;

bool prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x/i; i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(prime(x)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}