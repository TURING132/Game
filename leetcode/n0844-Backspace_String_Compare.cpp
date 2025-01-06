#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void shrink(string & s){
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='#')s[j++] = s[i];
            else j = j==0 ? j : j-1;
        }
        s = s.substr(0, j);
    }
    
    bool backspaceCompare(string s, string t) {
        shrink(s);
        shrink(t);
        return s == t;
    }
};

int main(){
    Solution solution = Solution();
    solution.backspaceCompare("ab#c", "ad#c");
    return 0;
}