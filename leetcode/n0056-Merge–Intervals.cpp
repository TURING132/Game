#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b) {
                return a[0] < b[0];
            }
        );
        vector<vector<int>> res;
        int beg = 0, end = 0;
        // [beg, end)
        while (end < intervals.size()) {
            beg = end;
            end = beg + 1;
            vector<int> interval = {intervals[beg][0], intervals[beg][1]};
            while(end < intervals.size() && intervals[end][0] <= interval[1]){
                interval[1] = max(interval[1], intervals[end][1]);
                end++;
            }
            res.emplace_back(interval);
        }
        return res;
    }
};