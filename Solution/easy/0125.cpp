/*
125. Valid Palindrome (https://leetcode.com/problems/valid-palindrome/description/)

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

ex:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:

    bool isAlphanumeric(char& a){
        if((int)('a')<=(int)(a) && (int)(a)<=(int)('z')){
            return true;
        }else if((int)('A')<=(int)(a) && (int)(a)<=(int)('Z')){
            a = (char)((int)(a)-(int)('A')+(int)('a'));
            return true;
        }else if((int)('0')<=(int)(a) && (int)(a)<=(int)('9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) { // using two pointers
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            bool l = isAlphanumeric(s[i]);
            bool r = isAlphanumeric(s[j]);
            if(l&&r){
                if(s[i]!=s[j]){
                    return false;
                }
                i += 1;
                j -= 1;
            }
            
            if(l==false){
                i += 1;
            }
            if(r==false){
                j -= 1;
            }
        }
        return true;
    }

    bool isPalindrome_v1(string s) {
        string palindrome = "";
        for(int i=0; i<s.length(); i++){
            if((int)('a')<=(int)(s[i]) && (int)(s[i])<=(int)('z')){
                palindrome += s[i];
            }
            else if((int)('A')<=(int)(s[i]) && (int)(s[i])<=(int)('Z')){
                palindrome += (char)((int)s[i] - (int)('A') + (int)('a'));
            }else if((int)('0')<=(int)(s[i]) && (int)(s[i])<=(int)('9')){
                palindrome += s[i];
            }
        }

        for(int i=0; i<(palindrome.length()/2); i++){
            if(palindrome[i] != palindrome[palindrome.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};