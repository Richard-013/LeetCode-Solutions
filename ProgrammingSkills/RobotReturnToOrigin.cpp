/*
* Result:
*
* Runtime: 9 ms
* Beats: 57.48%
*
* Memory: 9.30 MB
* Beats: 76.06%
*
* Problem:
*
* A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
*
* Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;

        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U') {
                vertical++;
                continue;
            } else if (moves[i] == 'D') {
                vertical--;
                continue;
            } else if (moves[i] == 'R') {
                horizontal++;
                continue;
            } else if (moves[i] == 'L') {
                horizontal--;
                continue;
            }
        }

        if (horizontal != 0 || vertical != 0) {
            return false;
        }

        return true;
    }
};
