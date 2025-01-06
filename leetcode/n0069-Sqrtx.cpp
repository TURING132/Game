# include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x == 1) return x;
        int left = 0, right = x, mid, result=0;
        while(left < right){
            // find the largest number thar n*n <= x
            mid = left +  (right - left) / 2;
            if((long long)mid * mid <= x){
                result = mid;
                left = mid+1;
            }else{// square > x
                right = mid;
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    printf("%d", solution.mySqrt(8));
}