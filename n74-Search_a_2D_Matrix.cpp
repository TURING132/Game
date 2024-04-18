# include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        // find the correct row by the first number in each row
        int left = 0, right = matrix.size(), mid;
        while(left < right){
            // [left, right)
            // find the last row that row[0] <= target
            mid = (left + right) / 2;
            if(matrix[mid][0] > target){
                right = mid;
            }else if(matrix[mid][0] < target){
                row = mid;
                left = mid+1;
            }else{
                return true;
            }
        }
        // find the correct col in this row
        left = 0; right = matrix[row].size();
        while(left < right){
            mid = (left + right) / 2;
            if(matrix[row][mid] > target){
                right = mid;
            }else if(matrix[row][mid] < target){
                left = mid + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> vec(1, std::vector<int>(1)); 
    vec[0][0] = 1;
    Solution solution;
    solution.searchMatrix(vec, 0);
    return 0;
}