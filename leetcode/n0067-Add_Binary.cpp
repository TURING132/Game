#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> A, B;
        for(int i =a.size() - 1; i>=0; i--) A.push_back(a[i] - '0');
        for(int i =b.size() - 1; i>=0; i--) B.push_back(b[i] - '0');
        if(A.size() < B.size()) swap(A, B);
        int t = 0;
        string C = "";
        for(int i = 0; i < A.size(); i++){
            t += A[i];
            if(i < B.size()) t+= B[i];
            C.push_back('0' + t%2);
            t/=2;
        }
        if(t) C.push_back('0'+t);
        reverse(C.begin(), C.end());
        return C;
        
    }
};