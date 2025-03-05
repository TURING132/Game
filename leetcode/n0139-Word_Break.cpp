#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 求排列，应该在外层遍历背包
        int n = s.size();
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> f(n+1, false);
        f[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                string word = s.substr(j, i - j);
                if(hash.count(word) && f[j]) f[i] = true;
            }
        }
        return f[n];
    }
};