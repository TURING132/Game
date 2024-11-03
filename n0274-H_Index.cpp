#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b){return a > b;});
        int h_index = 0;
        for(int i = 0; i < citations.size(); i++){
            if(i + 1 <= citations[i]){
                h_index = i + 1;
            }else break;
        }
        return h_index;
    }
};