class Solution {
public:
    int climbStairs(int n) {
        // f[n] = f[n-1] + f[n-2]
        if(n <= 2) return n;
        int a = 1, b = 2, c;
        for(int i = 0; i < n - 2; i++){
            c = a + b;
            a=  b;
            b=  c;
        }
        return b;
    }
};