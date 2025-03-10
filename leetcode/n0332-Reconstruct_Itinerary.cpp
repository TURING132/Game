#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int>> f2;
    int ticketsNum;
    vector<string> res;
    bool dfs(){
        if(res.size()>ticketsNum) return true;
        string cur = res.back();
        for(pair<const string, int> & t : f2[cur]){
            if(!t.second)continue;
            t.second--;
            res.push_back(t.first);
            if(dfs()) return true;
            t.second++;
            res.pop_back();
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        this->ticketsNum = tickets.size();
        for(vector<string> & vec : tickets){
            f2[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        dfs();
        return res;
    }
};