#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string a;
    int  b;
    vector<int>A;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0 ; i--) A.push_back(a[i] - '0');
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) {
        t += b * A[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    for(int i =C.size() - 1; i >=0;i-- ){
        cout << C[i];
    }
    return 0;
}