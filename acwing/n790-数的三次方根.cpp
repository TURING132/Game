#include <iostream>
using namespace std;
int main(){
    double x;
    scanf("%lf", &x);
    double l = -10000, r = 10000, mid;
    while(r - l > 1e-8) {
        mid = (l+r)/2;
        if(mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf", l);
    return 0;
}