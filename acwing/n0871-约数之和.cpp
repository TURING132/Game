#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

int main(){
    int n; scanf("%d", &n);
    unordered_map<int, int> primes;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        for(int i = 2; i <= x/i; i++){
            while(x%i == 0){
                x/=i;
                primes[i]++;
            }
        }
        if(x>1) primes[x]++;
    }

    LL res = 1;
    for(auto & p : primes){
        int a = p.first, b = p.second;
        LL t = 1;
        for(int i = 0; i < b; i++){
            t = (t * a + 1) % mod;
        }
        res = res * t % mod;
    }
    printf("%d", res);

    return 0;
}