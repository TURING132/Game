#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003;
const int null = 0x3f3f3f3f;

int h[N];

int find(int x){
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x){
        t++;
        if(t == N) t = 0;
    }
    return t;
}

int main(){
    memset(h, 0x3f, sizeof h);
    int n, x;
    char op[2];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", op);
        scanf("%d", &x);
        if(op[0] == 'I'){
            h[find(x)] = x;
        }else{
            if(h[find(x)] == null) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}