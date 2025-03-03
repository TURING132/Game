#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 求排列，应该在外层遍历物品
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> f(n + 1, false);
        f[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                string word = s.substr(j, i - j); // 从位置 j 到位置 i 的子字符串
                if (wordSet.find(word) != wordSet.end() && f[j]) { // 如果 word 存在于 wordSet 中，并且 f[j] 为 true（即 s 的前 j 个字符可以被拆分）
                    f[i] = true;
                }
            }
        }
        return f[n];
    }
};