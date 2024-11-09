#include <string>
using namespace std;
class Solution {
public:
    pair<int, string> I2R[13] = {
        {1000 , "M"},
        {900 , "CM"},
        {500 , "D"},
        {400, "CD"},
        {100 , "C"},
        {90 , "XC"},
        {50 , "L"},
        {40 , "XL"},
        {10 , "X"},
        {9, "IX"},
        {5 , "V"},
        {4 , "IV"},
        {1, "I"}
    };
    string intToRoman(int num) {
        string res = "";
        for( auto [key, value] : I2R){
            while(num >= key){
                res = res + value;
                num -= key;
            }
        }
        return res;
    }
};