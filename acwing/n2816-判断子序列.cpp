#include <iostream>
using namespace std;
const int N =  100010;
int a[N] = {0};
int b[N] = {0};

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n;i++)scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)scanf("%d", &b[i]);
    for(int i = 0, j = 0; i < n; j++){
        while(j < m && a[i] != b[j]) j++;
        if(j < m) i++;
        else {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}