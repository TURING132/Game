#include <iostream>
using namespace std;

const int N = 1000010;
bool st[N] = {false};
int primes[N], idx = 0;
int n;

int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])primes[idx++] = i;
        for(int j = 0; primes[j] <= n/i; j++){
            st[primes[j] * i] = true;
            if(i%primes[j] == 0) break;
        }
    }
    printf("%d", idx);
    return 0;
}