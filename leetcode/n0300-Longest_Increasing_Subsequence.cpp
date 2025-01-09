#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> lis = {nums[0]};
        for(int & num : nums) {
            if (lis.back() < num) lis.push_back(num);
            else {
                // find first num in num < lis 
                int l = 0, r = lis.size() - 1, mid;
                while (l < r) {
                    mid = l + r >> 1;
                    if(num <= lis[mid] ) r = mid; // dup ele will not change lis
                    else l = mid + 1;
                }
                if(num <= lis[l] ) lis[l] = num; 
            }
        }      
        return lis.size();
    }
};