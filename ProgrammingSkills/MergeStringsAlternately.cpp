/*
* You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
* If a string is longer than the other, append the additional letters onto the end of the merged string.
*
* Return the merged string.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedWord = "";
        short int word1Length = word1.length();
        short int word2Length = word2.length();

        if (word1Length > word2Length) {
            for (int i = 0; i < word2Length; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }

            for (int i = word2Length; i < word1Length; i++) {
                mergedWord += word1[i];
            }
        } else {
            for (int i = 0; i < word1Length; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }

            if (word1Length != word2Length) {
                for (int i = word1Length; i < word2Length; i++) {
                    mergedWord += word2[i];
                }
            }
        }

        return mergedWord;
    }
};
