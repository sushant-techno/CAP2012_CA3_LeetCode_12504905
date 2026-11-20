// LeetCode 283 - Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nextNonZero = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[nextNonZero], nums[i]);
                nextNonZero++;
            }
        }
    }
};
