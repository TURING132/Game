#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<long> cnt;
    std::priority_queue<long, vector<long>, greater<long>> h; 
    int mul[3] = {2, 3, 5};
    int nthUglyNumber(int n) {
        h.push(1);
        cnt.insert(1);
        for(int i = 0; i < n - 1; i++){
            long ugly = h.top();
            printf("%d\n", ugly);
            h.pop();
            for(int i = 0; i<3; i++){
                long nUgly = ugly * mul[i];
                if(!cnt.count(nUgly)){
                    cnt.insert(nUgly);
                    h.push(nUgly);    
                }
                
            }
        }
        return h.top();
    }
};