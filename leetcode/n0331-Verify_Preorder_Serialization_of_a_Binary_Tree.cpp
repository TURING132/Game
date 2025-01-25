#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i=0;
        int count = 1;
        while(i < preorder.size()){
            if(count <= 0) {cout << count << endl; return false;}

            if(preorder[i] == '#'){
                count --;
            }else{
                count++;
            }
            
            while(i<preorder.size() && preorder[i] != ',') i++;
            if(i < preorder.size()) i++;
            else break;
        }
        if(count != 0) {return false;}
        else return true;
    }
};