/*
* Result:
*
* Runtime: 0 ms
* Beats: 100.00%
*
* Memory: 7.78 MB
* Beats: 65.85%
*
* Problem:
*
* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int needleLength = needle.length();
        bool found = false;

        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] != needle[0]) {
                continue;
            }

            for (int j = 0; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }

                if (j == needleLength - 1) {
                    found = true;
                }
            }

            if (found) {
                index = i;
                break;
            }
        }

        return index;
    }
};
