#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;
        while(left < right){
            int water_height = min(left_max, right_max);
            if(height[left] <= water_height){
                result += water_height - height[left];
                left++;
                continue;
            }
            if(height[right] <= water_height){
                result += water_height - height[right];
                right--;
                continue;
            }
            left_max = max(height[left], left_max);
            right_max = max(height[right], right_max);
        }
        return result;
    }
};