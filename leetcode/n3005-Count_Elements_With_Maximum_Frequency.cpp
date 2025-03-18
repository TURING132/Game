#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>cnt(101, 0);
        int max_f = 0;
        for(auto & num : nums){
            cnt[num]++;
            max_f = max(max_f, cnt[num]);
        } 
        int res = 0;
        for(int i = 0; i < 101; i++){
            if(cnt[i] == max_f) res += max_f;
        }
        return res;
    }
};