#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int L = newInterval[0], R = newInterval[1];
        int size = intervals.size();
        bool in = false;
        vector<vector<int>> res;
        for(int i = 0; i < size; i++){
            if(intervals[i][1] < L) res.emplace_back(intervals[i]);
            else if(intervals[i][0] > R) {
                if (!in) {
                    res.emplace_back(vector({L, R}));
                    in = true;
                }
                res.emplace_back(intervals[i]);
            }else{
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
            }
        }
        if (!in) res.emplace_back(vector({L, R}));

        return res;
    }
};