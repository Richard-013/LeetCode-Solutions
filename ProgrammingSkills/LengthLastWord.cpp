/*
* Result:
*
* Runtime: 0 ms
* Beats: 100.00%
*
* Memory: 7.96 MB
* Beats: 42.91%
*
* Problem:
*
* Given a string s consisting of words and spaces, return the length of the last word in the string.
*
* A word is a maximal substring consisting of non-space characters only.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordLength = 0;

        for (string::iterator iter = s.end() - 1; iter != s.begin() - 1;
             iter--) {
            if (*iter != ' ') {
                lastWordLength++;
                continue;
            } else if (lastWordLength == 0) {
                continue;
            } else {
                break;
            }
        }

        return lastWordLength;
    }
};
