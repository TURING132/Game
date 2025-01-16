#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size()<4)return res;
        for(int i = 0; i < nums.size() - 3; i++) {
            while(i!=0 && i < nums.size() && nums[i] == nums[i-1])i++;
            for(int j = i+1; j < nums.size() -2; j++) {
                while(j!=i+1 && j < nums.size() && nums[j] == nums[j-1])j++;
                int l = j + 1;
                int r = nums.size()-1;
                while(l < r) {
                    long long sum = (long long )nums[i]+(long long )nums[j]+(long long )nums[l]+(long long)nums[r];
                    if( sum == target){
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        while(l < r && nums[l] == nums[l-1])l++ ;
                    }
                    else if(sum > target) r--;
                    else l++;
                }
            }
        }
        return res;
    }
};