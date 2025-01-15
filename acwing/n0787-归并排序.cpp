#include <iostream>
using namespace std;

const int N = 100010;
int n;
int num[N] = {0};
int tmp[N] = {0};

void mergeSort(int l, int r){
    if(l>=r) return;
    int mid = l + r >>1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int k = 0, i = l, j = mid +1;
    while(i<=mid && j <= r)
        if(num[i]<=num[j])tmp[k++] = num[i++];
        else tmp[k++] = num[j++];
    while(i<=mid)tmp[k++] = num[i++];
    while(j<=r)tmp[k++] = num[j++];
    for(int i =l, j=0; i <=r;i++, j++) num[i] = tmp[j];
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n;i++)scanf("%d",&num[i]);
    mergeSort(0, n-1);
    for(int i=0; i < n; i++)printf("%d ",num[i]);
    return 0;
}