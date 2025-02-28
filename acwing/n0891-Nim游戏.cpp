#include <iostream>
using namespace std;

int main(){
    int res = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        res ^= a;
    }
    if(res == 0) printf("No");
    else printf("Yes");
    return 0;
}