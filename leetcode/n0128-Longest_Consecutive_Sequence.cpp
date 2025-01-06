#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxLength = 0;
        for (int num : nums) {
            if(! set.count(num - 1)){
                int length = 1;
                while(set.count(++num)){
                    set.erase(num);
                    length ++;
                }
                maxLength = max(length, maxLength);
            }
        }
        return maxLength;
    }
};