/*
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (&nums.front() == &nums.back()) {
            return;
        }

        int* left = &nums[0];
        int* right = &nums[1];
        int* end = &nums.back();

        while (right != end + 1) {
            if (*left != 0) {
                left = right;
                right++;
                continue;
            } else if (*right == 0) {
                right++;
                continue;
            } else {
                *left = *right;
                *right = 0;
                left++;
                right++;
            }
        }
    }
};
