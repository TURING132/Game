#include <iostream>
using namespace std;
const int N = 100010;
const int M = 1000010;
int n, m;
char p[N], s[M];
int ne[M];

int main(){
    cin >> n >> p+1 >> m >> s+1;
    // 构造next
    for(int i = 2, j = 0; i < m; i++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1])j++;
        ne[i] = j;
    }
    // 匹配过程
    for(int i = 1, j = 0; i < m; i++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            printf("%d ", j - m);
        }
    }
    return 0;
}