#include <iostream>
using namespace std;
const int N = 100010;
int q[N] = {0}, hh, tt; // [hh, tt]

void init(){
    hh = 0;
    tt = -1;
}

void push(int x){
    q[++tt] = x;
}

void pop(){
    ++hh;
}

bool empty(){
    return tt < hh;
}

int query(){
    return q[hh];
}

int main(){
    init();
    int m;
    scanf("%d", &m);
    string op;
    int x;
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == "push"){
            scanf("%d", &x);
            push(x);
        }else if(op == "empty"){
            if(empty())printf("YES\n");
            else printf("NO\n");
        }else if(op == "pop"){
            pop();
        }else if(op == "query"){
            printf("%d\n", query());
        }
    }
    return 0;
}