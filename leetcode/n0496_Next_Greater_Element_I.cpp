#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>nge;
        vector<int> stk;
        vector<int> res;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!stk.empty() && stk.back() < nums2[i]){
                stk.pop_back();
            }
            if(!stk.empty()){
                nge[nums2[i]] = stk.back();
            }else{
                nge[nums2[i]] = -1;
            }
            stk.push_back(nums2[i]);
        }
        for(int num : nums1){
            res.push_back(nge[num]);
        }
        return res;
    }
};