#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // size of window is k + 1
        unordered_set<int> inWindow;
        for(int i = 0; i < nums.size(); i++) {
            if(i > k){
                inWindow.erase(nums[i - k -1]);
            }
            if(inWindow.count(nums[i])) return true;

            inWindow.emplace(nums[i]);
        }
        return false;
    }
};