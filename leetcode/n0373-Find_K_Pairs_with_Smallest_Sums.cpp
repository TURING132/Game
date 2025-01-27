#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return (a.first + a.second) > (b.first + b.second);
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> h(cmp);
        for(int & n1 : nums1){
            for(int & n2 : nums2){
                h.push({n1, n2});
            }
        }
        for(int i = 0; i < k; i++){
            res.push_back({h.top().first, h.top().second});
            h.pop();
        }
        return res;
    }
};