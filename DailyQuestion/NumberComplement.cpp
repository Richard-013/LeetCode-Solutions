/*
* Result:
*
* Runtime: 0 ms
* Beats: 100.00%
*
* Memory: 7.69 MB
* Beats: 8.34%
*
* Problem:
*
* The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
*
* Given an integer num, return its complement.
*/

#include <cmath>

class Solution {
public:
    int findComplement(int num) {
        if (num == 1) {
            return 0;
        }

        string binary = std::bitset<32>(num).to_string();

        if (binary[0] != '1') {
            binary.erase(0, binary.find_first_not_of('0'));
        }

        int binaryWordLength = binary.length();
        int output = 0;

        for (int i = 0; i < binaryWordLength; i++) {
            if (binary[i] == '0') {
                int power = binaryWordLength - (i + 1);
                output = output + pow(2, power);
            }
        }

        return output;
    }
};
