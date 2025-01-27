#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> h(&cmp); // (num, abs)
        for(int & n : arr){
            h.push({n , abs(n - x)});
        }
        vector<int> res; res.reserve(k);
        for(int i = 0; i < k; i++){
            res.push_back(h.top().first);
            h.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};