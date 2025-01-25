#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = INT_MIN;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int pos : houses){
            int l = 0, r = heaters.size()-1, mid;
            // find first heater >= pos
            while(l < r){
                mid = (l + r) >> 1;
                if(heaters[mid] >= pos) r = mid;
                else l = mid + 1;
            }
            int cloest =  abs(heaters[l] - pos);
            if(heaters[l] >= pos && l > 0) cloest = min(cloest, abs(heaters[l-1] - pos));
            res = max(res, cloest);
        }
        return res;
    }
};