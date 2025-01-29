#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> aph = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"},
        };
        vector<string> res;
        string cur;
        backtrack(res, aph, digits, 0, cur);
        return res;
    }

    void backtrack(vector<string>& res, const unordered_map<char, string>& aph, const string& digits, int idx, string& cur) {
        if(idx == digits.size()) res.push_back(cur);
        else {
            char c = digits[idx];
            const string & chars = aph.at(c); 
            for(const char & letter : chars){
                cur.push_back(letter);
                backtrack(res, aph, digits, idx+1, cur);
                cur.pop_back();
            }
        }
    }
};