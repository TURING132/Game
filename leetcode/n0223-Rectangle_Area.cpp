#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res = 0;
        res += (ax2 - ax1) * (ay2 - ay1);
        res += (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(bx1, ax1);
        int ovetlapHeight = min(ay2, by2) - max(by1, ay1);
        overlapWidth = max(overlapWidth, 0);
        ovetlapHeight = max(ovetlapHeight, 0);
        res -= overlapWidth * ovetlapHeight;
        return res;
    }
};