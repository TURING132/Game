#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for(int s : stones){
            pq.push(s);
        }
        cout << pq.size() << endl;
        while(pq.size()>1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a != b){
                cout << "push: " << a-b << endl;
                pq.push(a - b);
            }
            cout << pq.size() << endl;
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};