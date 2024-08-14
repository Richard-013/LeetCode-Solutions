/*
* You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
* If a string is longer than the other, append the additional letters onto the end of the merged string.
*
* Return the merged string.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        bool word1Small;

        if (word1.length() > word2.length()) {
            word1Small = false;
        } else {
            word1Small = true;
        }

        string mergedWord = "";

        if (word1Small) {
            int length = word1.length();
            for (int i = 0; i < length; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }

            if (word2.length() > word1.length()) {
                for (int i = length; i < word2.length(); i++) {
                    mergedWord += word2[i];
                }
            }
        } else {
            int length = word2.length();
            for (int i = 0; i < length; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }

            if (word1.length() > word2.length()) {
                for (int i = length; i < word1.length(); i++) {
                    mergedWord += word1[i];
                }
            }
        }

        return mergedWord;
    }
};
