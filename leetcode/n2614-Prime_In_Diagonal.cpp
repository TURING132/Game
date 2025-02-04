#include <vector>
using namespace std;
class Solution {
public:
    bool isPrime(int x){
        if(x < 2) return false;
        for(int i = 2; i <= x/i; i++){
            if(x%i==0) return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {      
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            if(isPrime(nums[i][i])) res = max(res, nums[i][i]);
        }
        for(int i = 0; i < n; i++){
            if(isPrime(nums[i][n-i-1])) res = max(res, nums[i][n-i-1]);
        }
        return res;
    }
};