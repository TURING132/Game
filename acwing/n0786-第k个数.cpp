#include <iostream>
using namespace std;

const int N = 100010;
int num[N] =  {0};
int qucikSearch(int l, int r, int k){
    if(l==r) return num[l];
    int i = l-1, j = r+1, x = num[l+r>>1];
    while(i < j){
        while(num[++i]<x);
        while(num[--j]>x);
        if(i<j) swap(num[i], num[j]);
    }
    int sl = j - l +1;
    if(k <= sl) return qucikSearch(l, j, k);
    else return qucikSearch(j+1, r, k - sl);
}


int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i=0; i < n;i++) scanf("%d",&num[i]);
    printf("%d", qucikSearch(0, n-1, k));
    return 0;
}