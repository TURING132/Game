#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool equationsPossible(vector<string>& equations) {
        p.resize(26);        
        for(int i = 0; i < 26; i++) p[i] = i;
        for(auto & e : equations){
            char a = e[0] - 'a', b = e[3] - 'a';
            if(e[1] == '='){
                p[find(a)] = find(b);
            }
        }
        for(auto & e : equations){
            char a = e[0] - 'a', b = e[3] - 'a';
            if(e[1] == '!' && find(a) == find(b)){
                return false;
            }
        }
        return true;
    }
};