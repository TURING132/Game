#include <iostream>
#include <string>
using namespace std;
const int N = 100010;
int h[N], k2h[N], h2k[N];
int siz = 0;
int n;

void hswap(int a, int b){
    swap(h[a], h[b]);
    swap(h2k[a], h2k[b]);
    swap(k2h[h2k[a]], k2h[h2k[b]]);
    
}

void up(int u){
    while(u / 2 && h[u] < h[u/2]){
        hswap(u, u/2);
        u  = u>> 1;
    }
    
}

void down(int u){
    int t = u;
    if(u * 2 <= siz && h[u*2] < h[t]) t=u*2;
    if(u*2 + 1 <= siz && h[u*2+1] < h[t]) t = u*2+1;
    if(t != u){
        hswap(u, t);
        down(t);
    }
}

int main(){
    scanf("%d", &n);
    string op;
    int a, b;
    int m = 0;
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == "I"){
            scanf("%d", &a);
            h[++siz] = a;
            k2h[++m] = siz;
            h2k[siz] = m;
            up(siz);
        }else if(op == "PM"){
            printf("%d\n", h[1]);
        }else if(op == "DM"){
            hswap(1, siz);
            siz--;
            down(1);
        }else if(op == "D"){
            scanf("%d", &a);
            int u = k2h[a];
            hswap(u, siz);
            siz--;
            down(u);
            up(u);
        }else if(op == "C"){
            scanf("%d%d", &a, &b);
            h[k2h[a]] = b;
            down(k2h[a]);
            up(k2h[a]);
        }
    }
    
    
    return 0;
}