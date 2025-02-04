#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1, 0);
        vector<int> outdeg(n+1, 0);
        vector<int> judge;
        for(vector<int> & t : trust){
            outdeg[t[0]]++;
            indeg[t[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(indeg[i] == n-1 && outdeg[i] == 0){
                judge.push_back(i);
            }
        }
        
        if(judge.size() == 1) return judge[0];
        else return -1;
    }
};