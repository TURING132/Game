#include <iostream>
using namespace std;

const int N = 100010;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x, res = 0;
        scanf("%d",&x);
        while(x>0){
            x -= (x&-x);
            res++;
        }
        printf("%d ",res);
    }

    return 0;
}