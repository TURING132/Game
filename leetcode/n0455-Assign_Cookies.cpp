#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int j = 0;
        for(int i=0; i < g.size() && j < s.size(); i++){ // child
            for(; j < s.size(); j++){
                if(g[i] <= s[j]){
                    res++;
                    j++;
                    break;
                }
            }
        }
        return res;
    }
};