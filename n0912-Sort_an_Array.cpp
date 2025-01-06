#include <vector>
using namespace std;

class Solution {
public:
    void quickSrotArray(vector<int> & nums, int left, int right) {
        // [left, right]
        if(left >= right) return;

        int i = left - 1, j = right + 1, pivot = nums[left + right >> 1];

        while (i < j) {
            while (nums[++i] < pivot);
            while (nums[--j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
        }

        quickSrotArray(nums, left, j);
        quickSrotArray(nums, j + 1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSrotArray(nums, 0, nums.size() - 1);
        return nums;
    }
};