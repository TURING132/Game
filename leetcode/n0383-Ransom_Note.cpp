#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) {
            return false;
        }
        vector<int> hash(26);
        for (char & c : magazine){
            hash[c - 'a'] ++;
        }
        for (char & c : ransomNote){
            hash[c - 'a'] --;
            if(hash[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};