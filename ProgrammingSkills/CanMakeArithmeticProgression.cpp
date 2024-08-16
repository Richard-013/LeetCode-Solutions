/*
* Result:
*
* Runtime: 8 ms
* Beats: 15.76%
*
* Memory: 11.92 MB
* Beats: 16.39%
*
* Problem:
*
* A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
*
* Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        short int arrSize = arr.size();

        // Insertion Sort on data
        int i = 1;

        while (i < arrSize) {
            int currentValue = arr[i];
            int j = i;

            while (j > 0 && arr[j - 1] > currentValue) {
                arr[j] = arr[j - 1];
                j--;
            }

            arr[j] = currentValue;
            i++;
        }

        int initialDiff = arr[1] - arr[0];

        for (int k = 2; k < arrSize; k++) {
            int diff = arr[k] - arr[k - 1];

            if (diff != initialDiff) {
                return false;
            }
        }

        return true;
    }
};
