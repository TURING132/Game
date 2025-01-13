#include <iostream>
using namespace std;

const int N = 100010;

int a[N] = {0}, s[N] = {0};

int main(){
    int n, m;
    scanf("%d%d", & n, & m);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)s[i] = s[i-1] + a[i];
    for(int i = 0; i < m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        cout << s[r] - s[l-1] << endl;
    }

    return 0;
}