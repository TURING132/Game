#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> left(size);
        // left to right
        for(int i = 0; i < size; i++){
            if(i != 0 && ratings[i] > ratings[i - 1]){
                left[i] = left[i - 1] + 1;
            }else{
                left[i] = 1;
            }
        }   
        int res = 0, right = 0;
        // right to left
        for(int i = size - 1; i >=0; i --){
            if(i != size - 1 && ratings[i] > ratings[i + 1]){
                right = right + 1;
            }else{
                right = 1;
            }
            res += max(left[i], right);
        }
        return res;
    }
};