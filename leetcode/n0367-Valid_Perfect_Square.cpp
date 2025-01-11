class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(mid*mid >= num) r = mid;
            else l = mid + 1;
        }      
        if(l * l == num) return true;
        else return false;
    }
};