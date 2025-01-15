#include <iostream>
using namespace std;
const int N = 100010;
int a[N] = {0};

int lowbit(int x){
    return x & -x;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int _ = 0; _ < n; _++) {
        int x;
        scanf("%d",&x);
        int res = 0;
        while(x != 0){
            res++;
            x -= lowbit(x);
        }
        printf("%d ", res);
    }
    return 0;
}