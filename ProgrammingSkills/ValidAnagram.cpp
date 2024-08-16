/*
* Result:
*
* Runtime: 13 ms
* Beats: 26.71%
*
* Memory: 8.76 MB
* Beats: 66.31%
*
* Problem:
*
* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
* An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if (s == t) {
            return true;
        }

        return false;
    }
};
