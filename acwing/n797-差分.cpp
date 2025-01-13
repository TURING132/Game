#include <iostream>
using namespace std;

const int N = 100100;
int a[N] = {0};
int b[N] = {0};

void insert(int l, int r, int c){
    // [l, r]
    b[l] += c;
    b[r+1] -= c;
}


int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i =1; i<= n;i++)scanf("%d", &a[i]);
    for(int i =1; i<= n;i++)insert(i,i,a[i]);
    for(int _ = 0; _ < m; _++){
        int l, r, c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l, r, c);
    }
    for(int i=1;i<=n;i++)b[i] = b[i] + b[i-1];
    for(int i=1;i<=n;i++)printf("%d ", b[i]);
    return 0;
}