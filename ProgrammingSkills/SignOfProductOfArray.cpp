/*
* Result:
*
* Runtime: 0ms
* Beats: 100.00%
*
* Memory: 12.77 MB
* Beats: 49.85%
*
* Problem:
*
* There is a function signFunc(x) that returns:
*    1 if x is positive.
*    -1 if x is negative.
*    0 if x is equal to 0.
*
* You are given an integer array nums. Let product be the product of all values in the array nums.
* 
* Return signFunc(product).
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int productSign = nums[0];

        if (productSign == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                return 0;
            }

            if (nums[i] < 0) {
                productSign = productSign * -1;
            } else {
                productSign = productSign * 1;
            }
        }

        if (productSign < 0) {
            return -1;
        } else {
            return 1;
        }
    }
};
