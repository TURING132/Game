#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> pri = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };
    stack<char> op;
    stack<int> nums;

    void eval(){
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char o = op.top(); op.pop();
        int res;
        if(o == '+'){
            res = a + b;
        }else if(o == '-'){
            res = a - b;
        }else if(o == '*'){
            res = a * b;
        }else{
            cout << a << "/" << b << endl;
            res = a / b;
        }
        cout << res << endl;
        nums.push(res);
    }

    int calculate(string s) {
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                int j = i;
                int x = 0;
                while(isdigit(s[j])){
                    x = x * 10 + (s[j] - '0');
                    j++;
                }
                nums.push(x);
                i = j - 1;
            }else if(s[i]==' ') continue;
            else {
                char o = s[i];
                while(!op.empty() && pri[o] <= pri[op.top()]){
                    eval();
                }
                op.push(o);
            }
        }
        while(!op.empty()){
            cout << "eval" << endl;
            eval();
        }
        return nums.top();
    }
};