#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;

int n;
int main(){
    unordered_map<int, int> primes;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", & x);
        for(int j = 2; j <= x/j; j++){
            while(x % j == 0){
                primes[j]++;
                x/=j;
            }
        }
        if(x > 1) primes[x] ++;
    }

    LL res = 1;
    for(auto & p : primes) res = res *  (p.second + 1) % mod;

    printf("%d", res);

    return 0;
}