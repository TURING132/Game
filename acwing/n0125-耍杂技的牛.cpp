#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int N = 50010;

typedef pair<int, int> PII;
int n;
PII cows[N];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int w, s;
        scanf("%d%d", &w, &s);
        cows[i] = {w + s, w};
    }
    sort(cows, cows + n);
    int sum = 0, res = INT_MIN;
    for(int i = 0; i < n; i++){
        int w = cows[i].second, s = cows[i].first - w;
        res = max(res, sum - s);
        sum+=w;
    }
    printf("%d", res);

    return 0;
}