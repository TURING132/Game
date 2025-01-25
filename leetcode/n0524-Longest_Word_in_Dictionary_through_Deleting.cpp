#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubstr(string & s, string & t){
        // find t in s
        if(s.size() < t.size()) return false;
        int ps = 0;
        for(int i =0; i < t.size(); i++){
            bool found = false;
            while(ps < s.size() && s[ps] != t[i]) ps++;
            if(ps < s.size() && s[ps] == t[i]){
                ps++;
                found = true;
            }
            if(!found) return false;
        }
        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string & a, const string & b){
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        for(int i = 0; i < dictionary.size(); i++){
            if(isSubstr(s, dictionary[i])) return dictionary[i];
        }
        return "";
    }
};