'''
28. Find the Index of the First Occurrence in a String (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

ex:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.


'''

class Solution {
public:
    int strStr_v1(string haystack, string needle) { // Naive approach

        if(haystack.length()<needle.length()){
            return -1;
        }

        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            int j = 0;
            while(j<needle.length()){
                if(haystack[i+j]==needle[j]){
                    j += 1;
                }else{
                    break;
                }
            }

            if(j==needle.length()){
                return i;
            }
        }
        return -1;
    }
};