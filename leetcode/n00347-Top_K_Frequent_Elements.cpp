#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second < n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int & num : nums){
            cnt[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> maxHeap(cmp);
        for(pair<int, int> p : cnt){
            maxHeap.push(p);
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return res;
    }
};