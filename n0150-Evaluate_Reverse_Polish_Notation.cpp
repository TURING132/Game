#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int a, b;
        for(string & s : tokens) {
            if (!(s == "+" || s == "-" || s == "*" || s == "/" )) {
                stack.push_back(stoi(s));
            } else {
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                if (s == "+") {
                    stack.push_back(a + b);
                } else if (s == "-") {
                    stack.push_back(b - a);
                } else if (s == "*") {
                    stack.push_back(a * b);
                } else if (s == "/") {
                    stack.push_back(b / a);
                }
            }
        }
        return stack[0];
    }
};