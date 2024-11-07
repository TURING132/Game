#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int start = 0;
        int cur = 0;
        while(start < size){// a round is enough, go out and no answer
            int j;
            cur = 0;
            for(j = 0; j < size; j++){
                int next = (start + j) % size;
                cur += gas[next];
                cur -= cost[next];
                if(cur < 0){
                    start = start + j + 1; // don't mod
                    break;
                } 
            }
            if(j == size) 
                return start;
        }
        return -1;
    }
};


int main(){
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution solution;
    printf("%d", solution.canCompleteCircuit(gas, cost));
    return 0;
}