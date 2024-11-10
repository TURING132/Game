#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int min_index = 0;
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < strs[min_index].size()) min_index = i;
        }
        int length = strs[min_index].size();
        int left = 0, right = length + 1, mid; // [left, right)
        while(left < right){
            mid = (left + right) / 2;
            if(hasCommonPrefix(strs, mid)){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        // when exit left = right = first unsatisfied index 
        return strs[min_index].substr(0, left - 1);
    }

    bool hasCommonPrefix(const vector<string> & strs, int len){
        string s1 = strs[0].substr(0, len);
        for(int i = 0; i< len; i++){
            for(int j = 0; j< strs.size(); j++){
                if(i >= strs[j].size() || s1[i] != strs[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
};