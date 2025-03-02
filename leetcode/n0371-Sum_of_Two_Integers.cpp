class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            unsigned int c = (a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};