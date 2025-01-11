#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n2c1, n2c2;
        for(int & num : nums1) {
            if(n2c1.count(num)) n2c1[num] ++;
            else n2c1[num] = 1;
        }
        for(int & num : nums2) {
            if(n2c2.count(num)) n2c2[num] ++;
            else n2c2[num] = 1;
        }
        vector<int> res;
        if(n2c1.size() > n2c2.size()) swap(n2c1, n2c2);
        for(const pair<int, int> p: n2c1) {
            for(int _ = 0; _ < p.second; _++){
                if(n2c2.count(p.first)&&n2c2[p.first]>0){
                    res.push_back(p.first);
                    n2c2[p.first]--;
                }
            }
        }
        return res;
    }
};