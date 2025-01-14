#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void insert(vector<int> & d,int l, int r, int c){
        d[r+1]-=c;
        d[l]+=c;
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> d(n+1, 0);
        for(int i =1; i <= bookings.size();i++){
            insert(d, bookings[i-1][0]-1, bookings[i-1][1]-1, bookings[i-1][2]);
        }
        for(int i=1; i < n; i++){
            d[i] = d[i] + d[i-1];
        }
        d.pop_back();
        return d;
    }
};