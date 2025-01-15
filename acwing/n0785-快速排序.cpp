#include <iostream>
using namespace std;

const int N = 100010;
int num[N] = {0};

void quickSort(int l, int r){
    if(l>=r) return;
    int i = l-1, j = r+1, mid = num[l+r>>1];
    while(i < j){
        while(num[++i]<mid);
        while(num[--j]>mid);
        if(i < j) swap(num[i],num[j]);
    }
    quickSort(l, j);
    quickSort(j+1, r);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i < n;i++) scanf("%d", &num[i]);
    quickSort(0, n-1);
    for(int i = 0; i < n;i++) printf("%d ", num[i]);
    return 0;
}