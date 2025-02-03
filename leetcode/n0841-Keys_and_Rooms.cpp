#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        int cnt = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int a = q.front(); q.pop();
            if(visited[a]) continue;
            visited[a] = true;
            cnt++;
            for(int & b : rooms[a])
                q.push(b);
        }
        return cnt == n;
    }
};