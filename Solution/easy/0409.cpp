/*
409. Longest Palindrome (https://leetcode.com/problems/longest-palindrome/description/)

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

ex:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> myMap;

        int length = 0;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(myMap.find(c)!=myMap.end()){
                myMap.erase(c);
                length += 2;
            }else{
                myMap[c] = 1;
            }
        }

        if(myMap.size()>0)
            length += 1;
        
        return length;
    }
};