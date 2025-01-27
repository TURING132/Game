#include <vector>
using namespace std;

class Solution {
public:
    vector<int> h;
    int size;
    
    void down(int idx){
        int m = idx;
        if(idx*2 <= size && h[idx*2] > h[m]) m = idx*2;
        if(idx*2+1 <= size && h[idx*2+1] > h[m]) m = idx*2 + 1;
        if(idx != m){
            swap(h[idx], h[m]);
            down(m);
        }
    }

    void del(){
        h[1] = h[size];
        size --;
        down(1);
    }

    int findKthLargest(vector<int>& nums, int k) {
        h.resize(nums.size()+1);
        h[0] = 0; size = h.size() - 1;
        copy(nums.begin(), nums.end(), h.begin() + 1);

        for(int i = size/2; i >= 1; i--) down(i);

        for(int i = 0; i < k - 1; i ++) del();

        return h[1];
    }
};