#include <iostream>
using namespace std;
const int N = 100010;
int p[N] = {0}, s[N] = {0};

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b){
    int seta = find(a), setb = find(b);
    p[seta] = setb;
    if(seta != setb)s[setb] += s[seta]; // 注意不通集合的时候菜肴增加大小
}

bool q1(int a, int b){
    return find(a) == find(b);
}

int q2(int x){
    return s[find(x)];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {p[i] = i; s[i] = 1;}
    string op;
    int a, b;
    for(int _ = 0; _ < m; _++){
        cin >> op;
        if(op == "C"){
            scanf("%d%d", &a, &b);
            merge(a, b);
        }else if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(q1(a, b)) printf("Yes\n");
            else printf("No\n");
        }else if(op == "Q2"){
            scanf("%d", &a);
            printf("%d\n", q2(a));
        }
    }
    return 0;
}