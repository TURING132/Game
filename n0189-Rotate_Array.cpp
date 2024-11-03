# include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int move = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + move);
        reverse(nums.begin() + move, nums.end());
    }
};