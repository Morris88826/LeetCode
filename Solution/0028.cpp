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

Hint: Review Rabin-Karp Algorithm

'''

class Solution {
public:

    int hashValue(string value, int RADIX, int MOD, int m){
        long out = 0;
        for(int i=0; i<m; i++){
            out = ((out*RADIX)%MOD + (int)(value[i]-'a'))%MOD;
        }
        return (int)out;
    }
    int strStr(string haystack, string needle) { // Rabin-Karp Algorithm
        
        if(haystack.length()<needle.length()){
            return -1;
        }

        int RADIX = 26;
        int MOD = 1000000033;
        int m = needle.length();

        int target = hashValue(needle, RADIX, MOD, needle.length());
        long _target = 0;

        long MAX_WEIGHT = 1;
        for(int i=0; i<needle.length(); i++){
            MAX_WEIGHT = (MAX_WEIGHT*RADIX)%MOD;
        }

        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            if(i==0){
                _target = hashValue(haystack, RADIX, MOD, m);
            }else{
                _target = ((_target*RADIX)%MOD - ((int)(haystack[i-1]-'a')*MAX_WEIGHT)%MOD + (int)(haystack[i+m-1]-'a')+MOD)%MOD; //prevent from having negative number
            }

            bool same = true;
            if(_target==target){
                for(int j=0; j<m; j++){
                    if(haystack[i+j]!=needle[j]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    return i;
                }
            }
            
        }
        return -1;
    }


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

    int strStrPractice(string haystack, string needle) {
        
    }
};