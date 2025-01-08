#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // find first i satisfy c[i] >= n - i
        int n = citations.size();
        int l = 0, r =  n - 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (citations[mid] >= n - mid) r = mid;
            else l = mid + 1;
        }
        if (citations[l] >= n - l) return n - l; // if result exist return
        else return 0; // if not exist, return 0
    }
};