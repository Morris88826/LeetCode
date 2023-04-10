/*
3. Longest Substring Without Repeating Characters (https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
Given a string s, find the length of the longest 
substring without repeating characters.

ex:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int l = 0;
        unordered_map<char, int> myMap;
        for(int i=0; i<s.length(); i++){
            if(myMap.find(s[i])!=myMap.end()){
                while(s[l]!=s[i]){
                    myMap.erase(s[l]);
                    l += 1;
                }
                l += 1;
            }
            myMap[s[i]] = 1;
            result = max(result, i-l+1);
        }
        return result;
    }
};