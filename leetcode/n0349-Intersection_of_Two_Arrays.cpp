#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(int & num : nums1) set1.insert(num);
        for(int & num : nums2) set2.insert(num);
        vector<int> res;
        if(set1.size() > set2.size()) swap(set1, set2);
        for(const int & num : set1){
            if(set2.count(num)) res.push_back(num);
        }
        return res;
    }
};