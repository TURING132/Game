#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // true question is, why greedy algorithm work?
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        
        int L = points[0][0], R = points[0][1];
        int count = 1;

        int size = points.size();
        for(int i = 1; i < size; i++){
            if (points[i][0] <= R){
                L = points[i][0];
                R = min(R, points[i][1]);
            }else{
                count ++;
                L = points[i][0];
                R = points[i][1];
            }
        }
        return count;
    }
};