#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        string des[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++){
            a.push_back({-score[i], i}); // {score, idx}
        }
        sort(a.begin(), a.end());
        vector<string> res(n);
        for(int i = 0; i < n; i++){
            if(i>=3){
                res[a[i].second] = to_string(i+1);
            }else{
                res[a[i].second] = des[i];
            }
        }
        return res;
    }
};