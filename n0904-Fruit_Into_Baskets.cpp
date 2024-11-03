#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // [beg, end]
        unordered_map<int, int> buckets;
        int res = 0;
        int beg = 0;
        for(int end = 0 ; end < fruits.size(); end++){
            buckets[fruits[end]] ++ ;
            while(buckets.size() > 2){
                auto it = buckets.find(fruits[beg]);
                it->second  -- ;
                if(it->second == 0){
                    buckets.erase(it);
                }
                beg ++;
            }
            res = max(res, end - beg + 1);
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> fruits = {1,2,1};
    printf("%d", solution.totalFruit(fruits));
    return 0;
}