#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<char, int> & a, const pair<char, int> & b){
        return a.second < b.second;
    }

    string frequencySort(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(&cmp)> h(cmp);
        unordered_map<char, int> cnt;
        for(char & c : s){
            cnt[c]++;
        }
        for(const pair<char, int> & p : cnt){
            h.push(p);
        }
        string res = "";
        while(!h.empty()){
            const pair<char,int> & p = h.top();
            for(int i = 0; i < p.second; i++){
                res += p.first;
            }
            h.pop();
        }
        return res;
    }
};