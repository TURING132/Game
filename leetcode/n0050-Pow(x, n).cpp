class Solution {
    public:
        double myPow(double x, int n) {
            double res = 1;
            long long N = n; // 因为正数的范围比较大，用longlong来防止-n越界
            if(N < 0){
                N = - N;
                x = 1 / x;
            }
            while(N){
                if(N & 1) res *= x;
                x *= x;
                N >>= 1;
            }
            return res;
        }
    };