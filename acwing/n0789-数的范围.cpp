#include <iostream>

using namespace std;

const int N = 100010;
int nums[N] = {0};

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        int l = 0, r = n - 1, mid;
        // find first
        while(l<r) {
            mid = l + r >> 1;
            if (nums[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(nums[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        }else {
            cout << l << " ";
        }
        // find last
        l = 0; r = n - 1;
        while(l < r) {
            mid = l + r + 1 >> 1;
            if(nums[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}