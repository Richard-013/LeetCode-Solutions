/*
* Result:
*
* Runtime: 225 ms
* Beats: 74.53%
*
* Memory: 107.92 MB
* Beats: 29.72%
*
* Problem:
*
* You are given m arrays, where each array is sorted in ascending order.
*
* You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
*
* Return the maximum distance.
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0].front();
        int smallestOrigin = 0;
        int biggest = arrays[0].back();
        int biggestOrigin = 0;
        int secondSmallest = arrays[1].front();
        int secondSmallestOrigin = 1;
        int secondBiggest = arrays[1].back();
        int secondBiggestOrigin = 1;

        for (int i = 0; i < arrays.size(); i++) {
            int tempSmall = arrays[i].front();

            if (tempSmall < smallest) {
                secondSmallest = smallest;
                secondSmallestOrigin = smallestOrigin;
                smallest = tempSmall;
                smallestOrigin = i;
            } else if (i != smallestOrigin && tempSmall <= secondSmallest) {
                secondSmallest = tempSmall;
                secondSmallestOrigin = i;
            }

            int tempBig = arrays[i].back();

            if (tempBig > biggest) {
                secondBiggest = biggest;
                secondBiggestOrigin = biggestOrigin;
                biggest = tempBig;
                biggestOrigin = i;
            } else if (i != biggestOrigin && tempBig >= secondBiggest) {
                secondBiggest = tempBig;
                secondBiggestOrigin = i;
            }
        }

        int result;

        if (smallestOrigin != biggestOrigin) {
            result = diff(smallest, biggest);
        } else {
            int diffWithSmallest = diff(smallest, secondBiggest);
            int diffWithBiggest = diff(secondSmallest, biggest);

            if (diffWithSmallest > diffWithBiggest) {
                result = diffWithSmallest;
            } else {
                result = diffWithBiggest;
            }
        }

        return result;
    }

    int diff(int lowValue, int highValue) {
        int diff;

        if (lowValue < 0 && highValue > 0) {
            diff = std::abs(std::abs(highValue) + std::abs(lowValue));
        } else {
            diff = std::abs(std::abs(highValue) - std::abs(lowValue));
        }

        return diff;
    }
};
