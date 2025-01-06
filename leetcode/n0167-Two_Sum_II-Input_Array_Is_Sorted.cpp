#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> result = {-1, -1};
        while (i <= j) {
            if(numbers[i] + numbers[j] < target) {
                i++;
            }else if(numbers[i] + numbers[j] > target) {
                j--;
            }else{
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }
        }
        return result;
    }
};