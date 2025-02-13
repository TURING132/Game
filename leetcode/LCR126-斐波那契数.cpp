const int N = 1e9+7;
class Solution {
public:
    int fib(int n) {
        if(n <= 1)return n;
        int a = 0, b = 1, c;
        for(int i = 0; i <n-1;i ++){
            c = (a + b)%N;
            a = b;
            b = c;
        } 
        return b;
    }
};