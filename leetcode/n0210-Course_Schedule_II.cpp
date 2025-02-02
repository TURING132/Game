#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> p;
    vector<vector<int>> edges;
    vector<int> d;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        d.resize(numCourses);
        edges.resize(numCourses);
        for(vector<int> & e : prerequisites){
            edges[e[1]].push_back(e[0]);
            d[e[0]]++;
        }

        queue<int> q;
        for(int i = 0; i  <numCourses; i++){
            if(d[i] == 0) {q.push(i), p.push_back(i);}
        }

        while(q.size()){
            int a = q.front(); q.pop();
            for(int & b : edges[a]){
                d[b]--;
                if(d[b] == 0){
                    q.push(b);
                    p.push_back(b);
                }
            }
        }

        if(p.size() == numCourses) return p;
        else return {};
    }
};