#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = 0; i < a.size();i++) A.push_back(a[i] - '0');
    int r = 0;
    vector<int> C; // A // B = C .. r
    for(int i = 0; i < A.size(); i++){
        r = r * 10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    for(int i = C.size()-1;i>=0;i--)cout << C[i];
    cout << endl << r;

    return 0;
}