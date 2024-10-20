#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, i = 0, j = -1;
        for(; i < nums.size(); i++){
            if(j == -1|| nums[i] != nums[j]){
                count = 1;
            }else{
                count ++;
            }
            if(count <= 2){
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};