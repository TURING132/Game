#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> f(s.size() + 1);
        // [0, r)
        f[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                string word = s.substr(j, i - j);
                if(wordSet.count(word) && f[j]) f[i] = true;
            }
        }
        return f[s.size()];
    }
};