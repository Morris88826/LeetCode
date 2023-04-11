/*
8. String to Integer (atoi) (https://leetcode.com/problems/string-to-integer-atoi/description/)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
The algorithm for myAtoi(string s) is as follows:
Read in and ignore any leading whitespace.

Check if the next character (if not already at the end of the string) is - or +. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer. If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

ex:
00000-42a1234 -> 0,    +0 123 -> 0, 4193 with words -> 4193

Beware how to handle overflow values
*/

#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 0;
        for(int i=0; i<s.length(); i++){
            if(sign==0 && s[i]==' '){
                // skip
            }else if(sign==0 && (s[i]=='+'||s[i]=='-') && (i!=s.length()-1) && ('0'<=s[i+1] && s[i+1]<='9')){
                sign = s[i]=='+'? 1: -1;
            }else if('0'<=s[i] && s[i]<='9'){
                sign = sign==0? 1: sign;
                int val = s[i]-'0';
                
                // deal with overflow
                if(sign==1){ // if positive
                    if(result>INT_MAX/10 || (result==INT_MAX/10 && val>=INT_MAX%10)){
                        return INT_MAX;
                    }
                }else{ // if negative
                    if(result>INT_MAX/10 || (result==INT_MAX/10 && val>=INT_MAX%10+1)){
                        return INT_MIN;
                    }
                }
                result = result*10 + val;
            }else{ // if not '0-9', ' ', '+', or '-'
                break;
            }
        }
        return result*sign;
    }
};