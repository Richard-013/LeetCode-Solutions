/*
* Result:
*
* Runtime: 0 ms
* Beats: 100.00%
*
* Memory: 7.76 MB
* Beats: 45.62%
*
* Problem:
*
* Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
*/

class Solution {
public:
    string toLowerCase(string s) {
        // Letters ordered by frequency of appearance in English words
        char letters[26][2] = {{'E', 'e'}, {'T', 't'}, {'A', 'a'}, {'O', 'o'},
                               {'I', 'i'}, {'N', 'n'}, {'S', 's'}, {'R', 'r'},
                               {'H', 'h'}, {'D', 'd'}, {'L', 'l'}, {'U', 'u'},
                               {'C', 'c'}, {'M', 'm'}, {'F', 'f'}, {'Y', 'y'},
                               {'W', 'w'}, {'G', 'g'}, {'P', 'p'}, {'B', 'b'},
                               {'V', 'v'}, {'K', 'k'}, {'X', 'x'}, {'Q', 'q'},
                               {'J', 'j'}, {'Z', 'z'}};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }

            for (int k = 0; k < 26; k++) {
                if (s[i] == letters[k][0]) {
                    s[i] = letters[k][1];
                }
            }
        }

        return s;
    }
};
