/*
* Result:
*
* Runtime: 0 ms
* Beats: 100.00%
*
* Memory: 10.64 MB
* Beats: 29.10%
*
* Problem:
*
* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
* The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
* Increment the large integer by one and return the resulting array of digits.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int* currentDigit = &digits.back();
        int* frontBound = &digits.front() - 1;

        while (currentDigit != frontBound) {
            if (*currentDigit != 9) {
                *currentDigit += 1;
                break;
            } else {
                *currentDigit = 0;

                if (currentDigit == frontBound + 1) {
                    digits.insert(digits.begin(), 1);
                    break;
                }

                currentDigit--;
            }
        }

        return digits;
    }
};
