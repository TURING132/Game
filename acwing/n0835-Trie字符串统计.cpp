#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26] = {0}, cnt[N], idx = 0;
char s[N];
// each i is a node, 0 is root and null
// son store idx of next node

void insert(char * s){
    int p = 0;
    for(int i = 0; s[i]; i++){
       int n = s[i] - 'a';
       if(son[p][n] == 0)son[p][n] = ++idx;
       p = son[p][n];
    }
    cnt[p]++;
}

int query(char * s){
    int p = 0;
    for(int i = 0; s[i]; i++) {
        int n = s[i] - 'a';
        if(son[p][n] == 0) return 0;
        p = son[p][n];
    }
    return cnt[p];
}

int main(){
    int n; scanf("%d", &n);
    char s[N] = {0};
    for(int _; _ < n; _++){
        char op[2];
        scanf("%s%s", op, s);
        if(op[0] == 'I'){
            insert(s);
        }else{
            printf("%d\n",query(s));
        }
    } 

    return 0;
}