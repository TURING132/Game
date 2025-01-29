#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long ULL;

const int N = 100010;
const int P = 13331;
ULL h[N], p[N];

ULL get(int l, int r){
    return h[r] - h[l-1] * p[r-l+1];
}

int main(){
    int n, m;
    string s;
    scanf("%d%d", &n, &m);
    cin >> s;

    p[0] = 1;
    for(int i = 1; i  <=n; i++){
        h[i] = h[i-1] * P + s[i-1];
        p[i] = p[i-1] * P;
    }
    int l1, r1, l2, r2;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(get(l1, r1) == get(l2, r2)){
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}