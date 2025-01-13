#include <vector>
#include <iostream>
#include <random>
using namespace std;

class Solution {
public:
    vector<vector<int>> rects;
    vector<int> s;
    mt19937 gen{random_device{}()};
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        s.resize(rects.size()+1, 0);
        for(int i = 1; i < s.size(); i++) s[i] = s[i-1] + (rects[i-1][2]-rects[i-1][0]+1)*(rects[i-1][3]-rects[i-1][1]+1);
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, s.back() - 1); // [l, r]
        int k = dis(gen) % s.back();
        int index = upper_bound(s.begin(), s.end(), k) - s.begin() - 1;
        k = k - s[index];
        int a = rects[index][0], b = rects[index][1], x = rects[index][2], y = rects[index][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return {a + da, b + db};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */