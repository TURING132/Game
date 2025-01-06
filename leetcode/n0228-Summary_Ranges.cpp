
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int beg = 0;
        int end = 0;
        int size = nums.size();
        vector<string> res;
        while(end < size){
            // [beg, end)
            // the point is each position will be scanned once, so a variable end is enough
            beg = end;
            end++;
            while(end < size && nums[end] == nums[end-1]+1){
                end++;
            }
            string s;
            if (end - 1 == beg) {
                s = to_string(nums[beg]);
            }else{
                s = to_string(nums[beg]) + "->" + to_string(nums[end - 1]);
            }
            res.emplace_back(s);
        }
        return res;
    }
};