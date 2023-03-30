/*
28. Find the Index of the First Occurrence in a String (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

ex:

Input: haystack = sadbutsad, needle = sad
Output: 0
Explanation: sad occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = leetcode, needle = leeto
Output: -1
Explanation: leeto did not occur in leetcode, so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

Hint: Review Rabin-Karp Algorithm
*/

#include <iostream>  
#include <string>
using namespace std;

class Solution {
public:

    int hashValue(string value, int RADIX, int MOD, int m){
        long out = 0;
        for(int i=0; i<m; i++){
            out = ((out*RADIX)%MOD + (int)(value[i]-'a'))%MOD;
        }
        return (int)out;
    }

    int strStr(string haystack, string needle) { // Rabin-Karp Algorithm, beware the overflow problem
        
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
};

class Solution_RabinKarp { //double hash to futher prevent spurious hits
public:
    int RADIX1 = 26;
    int RADIX2 = 27;

    int MOD1 = 10^7 + 33;
    int MOD2 = 2^31 - 1;

    pair<int, int> hashValue(string value, int m){
        long hv1 = 0;
        long hv2 = 0;
        for(int i=0; i<m; i++){
            hv1 = ((hv1*RADIX1)%MOD1 + (int)(value[i]-'a'))%MOD1;
            hv2 = ((hv2*RADIX2)%MOD2 + (int)(value[i]-'a'+1))%MOD2;
        }
        return make_pair(hv1, hv2);
    }
    int strStr(string haystack, string needle) {
        
        if(haystack.length()<needle.length()){
            return -1;
        }

        int m = needle.length();

        pair<int,int> target = hashValue(needle, m);
        pair<long,long> _target = make_pair(0,0);

        long MAX_WEIGHT1 = 1;
        long MAX_WEIGHT2 = 1;
        for(int i=0; i<m; i++){
            MAX_WEIGHT1 = (MAX_WEIGHT1*RADIX1)%MOD1;
            MAX_WEIGHT2 = (MAX_WEIGHT2*RADIX2)%MOD2;
        }


        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            if(i==0){
                _target = hashValue(haystack, m);
            }else{
                _target.first = ((_target.first*RADIX1)%MOD1 - ((int)(haystack[i-1]-'a')*MAX_WEIGHT1)%MOD1 + (int)(haystack[i+m-1]-'a')+MOD1)%MOD1; //prevent from having negative number

                _target.second = ((_target.second*RADIX2)%MOD2 - ((int)(haystack[i-1]-'a'+1)*MAX_WEIGHT2)%MOD2 + (int)(haystack[i+m-1]-'a'+1)+MOD2)%MOD2;
            }


            if(_target.first==target.first && _target.second == target.second){
                bool same = true;
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
};