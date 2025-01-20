#include <iostream>
using namespace std;
const int N = 100010;
int head, e[N] = {0}, ne[N] = {0}, idx;

void init(){
    head = -1; // tail always be -1
    idx = 0;
}

void insert(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void insert_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void dele(int k){
    if(k == -1) head = ne[head];
    else ne[k] = ne[ne[k]];
}

int main(){
    init();
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        char op;
        int x, k;
        cin >> op;
        if(op == 'H'){
            scanf("%d", &x);
            insert_to_head(x);
        }else if(op == 'I'){
            scanf("%d%d",&k,&x);
            insert(k-1, x);
        }else if(op == 'D'){
            scanf("%d",&k);
            dele(k-1);
        }
    }
    for(int i = head; i != -1; i=ne[i]) printf("%d ", e[i]);
    return 0;
}