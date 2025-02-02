#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> d;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        d.resize(numCourses);
        for(vector<int> & e : prerequisites){
            edges[e[0]].push_back(e[1]);
            d[e[1]]++;
        }

        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < numCourses; i++){
            if(d[i] == 0) {q.push(i); cnt ++;};
        }

        while(q.size()){
            int a = q.front(); q.pop();
            for(int & b : edges[a]){
                d[b]--;
                if(d[b] == 0){
                    cnt ++;
                    q.push(b);
                }
            }
        }
        return cnt == numCourses;
    }
};