#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int map[26] = {0};
        for(char & c : s){
            map[c - 'a'] ++;
        }
        for(char & c : t){
            map[c - 'a'] --;
            if(map[c - 'a'] < 0) return false;
        }
        return true;
    }
};