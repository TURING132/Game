#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cnt;
        for(int & n : nums){
            if(cnt.count(n)){
                return true;
            }
            cnt.insert(n);
        }
        return false;
    }
};