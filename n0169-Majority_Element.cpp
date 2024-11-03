#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int major = 0, cnt = 0;
        for(int num: nums){
            hash[num] ++;
            if(hash[num] > cnt){
                major = num;
                cnt = hash[num];
            }
        }
        return major;
    }
};