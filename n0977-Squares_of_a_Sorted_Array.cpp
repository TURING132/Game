#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int k = n - 1;
        for(int i = 0, j = n-1; i <= j ;){
            int a = nums[i] * nums[i], b = nums[j] * nums[j];
            if(a < b ){
                res[k--] = b;
                j--;
            }else{
                res[k--] = a;
                i++;
            }
        }
        return res;
    }
};

int main(){
    Solution solution = Solution();
    vector<int> vec = {-4,-1,0,3,10};
    solution.sortedSquares(vec);
    return 0;
}