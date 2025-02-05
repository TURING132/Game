#include <iostream>

using namespace std;

const int N = 1000010;
int primes[N], idx = 0;
int euler[N];
bool st[N];

void get_euler(int n){
    euler[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[idx++] = i;
            euler[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n/i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) {
                euler[primes[j] * i] = euler[i] * primes[j];
                break;
            }
            euler[primes[j] * i] = euler[i] * (primes[j] - 1);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    get_euler(n);
    long long res = 0;
    for(int i = 1; i <= n; i++){
        res += euler[i];
    }
    printf("%lld", res);
    return 0;
}