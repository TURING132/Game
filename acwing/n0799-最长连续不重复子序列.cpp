#include <iostream>
using namespace std;

const int N = 100010;
int a[N] = {0}, h[N] = {0};
int main(){
    int n;
    int res = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0,j=0;i<n;i++){
        h[a[i]]++;
        while(h[a[i]]>1){
            h[a[j]]--;
            j++;
        }
        res = max(res, i - j +1);
    }
    printf("%d", res);
    return 0;
}