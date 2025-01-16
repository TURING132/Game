#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> split(string s, char c){
        vector<string>res;
        //[l, r)
        int l = 0, r = 0;
        while(r < s.size()){
            while(r < s.size() && s[r]!=c) r++;
            res.push_back(s.substr(l, r));
            l = r+1;
            r = l;
        }
        return res;
    }

    int compareVersion(string version1, string version2) {
        auto strs1 = split(version1, '.');
        auto strs2 = split(version2, '.');
        int i;
        for(i = 0; i < strs1.size();i++){
            int v1 = 0 , v2 = 0;
            v1 = stoi(strs1[i]);
            if(i < strs2.size())v2 = stoi(strs2[i]);
            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
        }
        for(; i < strs2.size();i++){
            int v2 = stoi(strs2[i]);
            if(v2>0) return -1;
        }
        
        return 0;
    }
};