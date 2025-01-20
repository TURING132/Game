#include <iostream>
using namespace std;
const int N = 100010;

int e[N], l[N], r[N], idx;

void init(){
    // 0 is dummy head, 1 is dummy tail
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void insertR(int k, int x){ // insert after k
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void insertL(int k, int x){ // insert before k
    e[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    r[l[k]] = idx;
    l[k] = idx;
    idx++;
}

void dele(int k){// remove k
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void L(int x){
    insertR(0, x);
}

void R(int x){
    insertL(1, x);
}

int main(){
    init();
    int m;
    scanf("%d", &m);
    for(int _ = 0; _ < m; _++){
        int k, x;
        string op;
        cin >> op;
        if(op == "L"){
            scanf("%d", &x);
            L(x);
        }else if(op == "R"){
            scanf("%d", &x);
            R(x);
        }else if(op == "D"){
            scanf("%d", &k);
            dele(k+1);
        }else if(op == "IL"){
            scanf("%d%d", &k, &x);
            insertL(k+1, x);
        }else if(op == "IR"){
            scanf("%d%d", &k, &x);
            insertR(k+1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]){
        printf("%d ", e[i]);
    }
    return 0;
}