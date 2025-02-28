#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1 > l2) return false;
        vector<int> cnt;
        for(int i = 0; i < l1; i++){
            cnt[s1[i] - 'a'] --;
        }
        int l = 0;
        for(int r = 0; r < l2; r++){
            int x = s2[r] - 'a';
            cnt[x] ++;
            while(cnt[x] > 0){
                cnt[s1[l] - 'a']--;
                l++;
            }
            if(r - l + 1 == l1) return true;
            // 如果长度为l1，那么l1个1会分布在cnt中
            // 因为不存在正数，所以恰好填补了负数的空缺
        }
        return false;
    }
};