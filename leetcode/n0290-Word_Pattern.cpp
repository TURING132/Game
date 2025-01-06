#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<string> split(string s){
        istringstream iss(s);
        return {istream_iterator<string>{iss}, istream_iterator<string>{}};
    }

    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        if(pattern.size() != words.size()) return false;
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string s = words[i];
            if(c2s.count(c) && c2s[c] != s || s2c.count(s) && s2c[s] != c){
                return false;
            }
            c2s[c] = s;
            s2c[s] = c;
        }
        return true;
    }
};