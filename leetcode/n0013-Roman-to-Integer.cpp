#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char, int>R2I = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(i != s.size() - 1 && R2I[s[i]] < R2I[s[i + 1]] ){
                result -= R2I[s[i]];
            }else{
                result += R2I[s[i]];
            }
        }
        return result;
    }
};