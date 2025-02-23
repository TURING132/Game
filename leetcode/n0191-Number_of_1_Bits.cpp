class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n){
            res++;
            n -= n & (-n);
        }
        return res;
    }
};