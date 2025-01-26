#include <iostream>
using namespace std;

int n, m;
const int N = 100010; // heap begin in 1
int siz = 0;
int h[N];

void down(int u){
    int t = u;
    if(u*2<=siz && h[u*2] < h[t]) t = u*2;
    if(u*2+1<=siz && h[u*2+1] < h[t]) t = u*2+1;
    if(t!=u) {
        swap(h[u], h[t]);
        down(t);
    }
}

void del(){
    h[1] = h[siz];
    siz-=1;
    down(1);
}

void build(){
    siz = n;
    for(int i = siz/2; i>=1; i--){
        down(i);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    build();
    for(int i = 0; i < m; i++) {
        printf("%d ", h[1]);
        del();
    }

    return 0;
}