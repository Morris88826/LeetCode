/*
5. Longest Palindromic Substring (https://leetcode.com/problems/longest-palindromic-substring/description/)

Given a string s, return the longest 
palindromic substring in s.

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Input: s = "cbbd"
Output: "bb"
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    string longestPalindrome(string s) { // O(n^2) and also use less space
        if(s==""){
            return s;
        }

        int longest = 0;
        string result = "";
        for(int i=0; i<s.length(); i++){ // assume i is the middle of the palindrome

            // odd
            int l = 0;
            int r = 0;
            while(i-l>=0 && i+r<s.length() && s[i-l]==s[i+r]){
                if(l+r+1>longest){
                    longest = l+r+1;
                    result = s.substr(i-l, longest);
                }
                l += 1;
                r += 1;
            }

            // even 
            l = 1;
            r = 0;
            while(i-l>=0 && i+r<s.length() && s[i-l]==s[i+r]){
                if(l+r+1>longest){
                    longest = l+r+1;
                    result = s.substr(i-l, longest);
                }
                l += 1;
                r += 1;
            }

        }
        return result;
    }

    string longestPalindrome_v1(string s) { // Solved using Dynamic Programming Approach(tabulation)
        if(s==""){
            return s;
        }

        int longest = 1;
        string result = s.substr(0, longest);;
        vector<vector<int>> table;
        for(int i=0; i<s.length(); i++){
            vector<int>row(s.length(), -1);
            row[i] = 1;
            for(int j=0; j<i; j++){
                if((s[j]==s[i]) && (table[i-1][j+1] != 0)){
                    row[j] = 1;
                    if(i-j+1>longest){
                        longest = i-j+1;
                        result = s.substr(j, longest);
                    }
                }else{
                    row[j] = 0;
                }
            }
            table.push_back(row);
        }
        return result;
    }
};