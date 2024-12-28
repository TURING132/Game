#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMaps;
        unordered_map<char, char> tMaps;
        if (s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            char sChar = s[i];
            char tChar = t[i];
            if (sMaps.count(sChar) && sMaps[sChar] != tChar || tMaps.count(tChar) && tMaps[tChar] != sChar){
                return false;
            }
            sMaps[sChar] = tChar;
            tMaps[tChar] = sChar;
        }
        return true;
    }
};