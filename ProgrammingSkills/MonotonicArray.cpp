/*
* Result:
*
* Runtime: 104 ms
* Beats: 84.71%
*
* Memory: 99.40 MB
* Beats: 9.69%
*
* Problem:
*
* An array is monotonic if it is either monotone increasing or monotone decreasing.
*
* An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
* An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
*
* Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int numSize = nums.size();

        if (numSize <= 2) {
            return true;
        }

        int increasing = -1;
        int* index = &nums[1];
        int* endPoint = &nums[numSize];

        while (index != endPoint) {
            int* previous = index - 1;

            if (increasing == -1) {
                if (*index == *previous) {
                    index++;
                    continue;
                }

                if (*index > *previous) {
                    increasing = 1;
                } else {
                    increasing = 0;
                }
            }

            if (increasing == 1) {
                if (*index < *previous) {
                    return false;
                }
            } else {
                if (*index > *previous) {
                    return false;
                }
            }

            index++;
        }

        return true;
    }
};
