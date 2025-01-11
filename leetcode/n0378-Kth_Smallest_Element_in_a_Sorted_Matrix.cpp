#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& matrix, int k, int x) {
        int count = 0;
        int i = matrix.size()-1, j = 0;
        while(i>=0 && j <= matrix.size()-1){
            if(matrix[i][j] <= x) { // if [i][j] <= x, all above <= x
                count += i + 1;
                j++;
            }else{
                i--;
            }
        }
        if(count >= k) return true;
        else return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix[matrix.size()-1][matrix.size()-1];
        int mid;
        while(l < r){ // find first num, that count >= k
            mid = (l + r) >> 1;
            if(check(matrix, k, mid)) r = mid;
            else l  = mid+1;
        }
        return l;
    }   
};