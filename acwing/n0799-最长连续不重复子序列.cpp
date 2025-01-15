#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 100010;
int q[N] = {0}, c[N] = {0};


int main(){
    int n;
    int res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d",&q[i]);
    for(int i = 0, j = 0; i < n; i++) {
        c[q[i]]++;
        while(c[q[i]] > 1) {
            c[q[j]]--;
            j++;
        }
        res = max(res, i - j +1);
    }
    cout << res;
    return 0;
}