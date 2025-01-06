
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string getKey(string s) {
        int keys[26] = {0};
        for(char & c : s) {
            keys[c - 'a'] ++;
        }
        stringstream keyStream;
        for(int i = 0; i < 26; i++){
            keyStream << "#" << keys[i];
        }
        return keyStream.str();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string & s : strs){
            string key = getKey(s);
            map[key].emplace_back(s);
        }
        vector<vector<string>> results;
        for (auto & pair : map){
            results.emplace_back(pair.second);
        }
        return results;
    }
};