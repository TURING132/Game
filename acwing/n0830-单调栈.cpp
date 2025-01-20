#include <iostream>
using namespace std;
const int N = 100010;
int stk[N] = {0}, tt = 0;

int main(){
    int n, x;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        while(tt>0 && x <= stk[tt]) tt--;
        if(tt > 0) cout << stk[tt] << " ";
        else cout << "-1 ";
        stk[++tt] = x;
    }
    return 0;
}