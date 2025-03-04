#include <vector>
using namespace std;

class Solution {
public:
    int qmi(int a, int n){
        int res = 1, t = a;
        while(n){
            if(n & 1) res *=t;
            t *= t;
            n >>= 1;
        }
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        for(int i = 0; i < qmi(2, n); i++){
            vector<int> path;
            int t = i, idx = 0;
            while(t){
                if(t&1)path.push_back(nums[idx]);
                idx++;
                t>>=1;
            }
            res.push_back(path);
        }
        return res;
    }
};