#include <vector>
using namespace std;

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        // for i >= x, cnt[i] > i find first
        // for i < x, cnt [i] <= i
        // nums: 1 2 3 4
        // cnt : 1 3 4 5
        // nums: 1 2 3 4
        // cnt:  1 2 4 5
        int n = nums.size();
        int l = 1, r = n - 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid) cnt ++;
            }
            if(cnt > mid) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};