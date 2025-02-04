#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> st(n, false);
        vector<int> primes;
        for(int i = 2; i < n; i++){
            if(!st[i]){
                primes.push_back(i);
                for(int j = i + i; j < n; j += i){
                    st[j] = true;
                }
            }
        }
        return primes.size();
    }
};