#include <iostream>
using namespace std;
const int N = 500010;
int p[N], d[N]; // d[x] 存的是 x到p[x]的距离
int n, m;

int find(int x){
    if(p[x]!=x){
        int t = find(p[x]); 
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) p[i] = i;
    int res = 0;
    for(int i = 0; i < m; i++){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        
        if(x > n || y > n) res++;
        else{
            int px = find(x), py = find(y);
            if(t == 1){
                if(px == py && (d[x] - d[y]) %3 != 0){
                    res++;
                }else if(px != py){ // 同类，合并
                    p[px] = py;
                    d[px] = d[y] - d[x];// 保证 d[x] %3 = d[y] %3 == 0
                }
            }else{
                if(px == py && (d[x] - d[y] - 1) %3 != 0){
                    res++;
                }else if(px != py){
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d", res);
    
    return 0;
}