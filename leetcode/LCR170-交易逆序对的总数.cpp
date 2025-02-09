#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<int> tmp;
    int mergeSort(vector<int>& q, int l, int r){
        if(l >= r)return 0;
        int mid = (l+r)>>1;
        int res = mergeSort(q, l, mid) + mergeSort(q, mid+1, r);
        int i = l, j = mid+1, k = 0;
        while(i <= mid && j <= r){
            if(q[i] <= q[j]) tmp[k++] = q[i++];
            else{
                tmp[k++] = q[j++];
                res += mid - i +1;
            }
        }
        while(i <= mid) tmp[k++] = q[i++];
        while(j <= r) tmp[k++] = q[j++];
        for(int i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
        return res;
    }

    int reversePairs(vector<int>& record) {
        n = record.size();
        tmp = vector<int>(n);
        return mergeSort(record, 0, n-1);
    }
};

