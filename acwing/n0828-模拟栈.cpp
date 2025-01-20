#include <iostream>
using namespace std;

const int N = 100010;
int s[N], tt;

void init(){
    tt = 0;
}

void push(int x){
    s[tt++] = x;
}

void pop(){
    tt --;
}

bool empty(){
    return tt == 0;
}

int query(){
    return s[tt-1];
}

int main(){
    int m;
    scanf("%d", &m);
    string op;
    int x;
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == "push"){
            scanf("%d", &x);
            push(x);
        }else if(op == "query"){
            printf("%d\n", query());
        }else if(op == "empty"){
            if(empty())printf("YES\n");
            else printf("NO\n");
        }else if(op == "pop"){
            pop();
        }
    }
    return 0;
}