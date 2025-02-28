// 1 win 2 win 3 win 4 lose 5 
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};