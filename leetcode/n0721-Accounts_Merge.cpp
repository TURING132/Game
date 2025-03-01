#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // set <idx of account> 对账号进行合并
        // email -> idx of account 从邮箱映射到账号，以便合并
        // idx of account -> unorder_set<email> 构造每个账号的邮箱，需要进行去重
        int n = accounts.size();
        p.resize(n, 0);
        for(int i = 0; i < n; i++) p[i] = i;
        unordered_map<string, int> e2a;
        for(int i = 0; i < n; i++){
            string & a = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++){
                string & e = accounts[i][j];
                if(e2a.count(e)) p[find(i)] = find(e2a[e]);
                else e2a[e] = i;
            }
        }
        unordered_map<int, unordered_set<string>> a2e;
        for(const pair<string, int> & p : e2a){
            int root = find(p.second);
            a2e[root].insert(p.first);
        }
        vector<vector<string>> res;
        for(const pair<int, unordered_set<string>> & p : a2e){
            vector<string> a;
            a.push_back(accounts[p.first][0]);
            vector<string> emails(p.second.begin(), p.second.end());
            sort(emails.begin(), emails.end());
            a.insert(a.end(), emails.begin(), emails.end());
            res.push_back(a);
        }
        return res;
    }
};