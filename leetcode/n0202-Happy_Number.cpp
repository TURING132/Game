#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:

    bool isHappy(int n) {
        int num = n;
        set<int> checked;
        for(int i = 0; i < 1000; i++){
            if (checked.count(num)) return false;
            int newNum = 0;
            while(num > 0){
                newNum += (num % 10) * (num % 10);
                num /= 10;
            }
            if(newNum == 1) return true;
            num = newNum;
        }
        return false;
    }
};