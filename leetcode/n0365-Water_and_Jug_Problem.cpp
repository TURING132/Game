class Solution {
public:
    int gcd(int x, int y){
        return y == 0 ? x : gcd(y, x%y);
    }
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        if(x == 0 || y == 0) return target == 0 || x + y == target;
        int d = gcd(x, y);
        if(target % d)return false;
        else return true;
    }
};