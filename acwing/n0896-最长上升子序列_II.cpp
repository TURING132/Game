#include <iostream>
using namespace std;
const int N = 100010;
int a[N], q[N];
int n;
// 对于每一个长度，我们只需要存一个结尾最小的
// q 是单调递增的
int main(){
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)scanf("%d", &a[i]);
    int len = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = len;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(q[mid] < a[i]) l = mid;
            else r= mid  - 1;
        }
        len = max(len, r+1);
        q[r+1] =a[i];
    }

    printf("%d\n", len);
    
    return 0;
}