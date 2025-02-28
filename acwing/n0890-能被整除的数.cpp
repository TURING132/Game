#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 20;
int n, m;
int p[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) scanf("%d", &p[i]);
    int res = 0;
    for(int i = 1; i < 1 << m; i++){ // 2^m
        int t = 1, cnt = 0; // cnt 存的是集合数量
        for(int j = 0; j < m; j++)
            if(i >> j & 1){
                cnt ++;
                if((LL)t * p[j] > n){ // 如果太大了，大于n，那肯定不能整除
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        if(t != -1){
            if(cnt %2 ) res += n / t;
            else res -= n / t;
        }
    }
    printf("%d", res);
    return 0;
}