/*
7. Reverse Integer (https://leetcode.com/problems/reverse-integer/description/)
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

ex:
Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21

// beware edge cases such as -10, -100, ...
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        if(x==INT_MIN){
            int num = INT_MAX;
            result = result*10 + num%10 + 1;
            num /= 10;
            while(num>0){
                if(result>(INT_MAX/10)||((result==(INT_MAX/10))&&(num%10>INT_MAX%10))){ // overflow
                    return 0;
                }
                result = result*10 + num%10;
                num /= 10;
            }
            result *= -1; 
            return result;
        }

        bool neg = x>0? false: true;
        if(neg){
            x = x*-1;
        }
        while(x>0){
            if(result>(INT_MAX/10)||((result==(INT_MAX/10))&&(x%10>INT_MAX%10))){
                return 0;
            }
            result = result*10 + x%10;
            x /= 10;
        }
        return neg? -1*result: result;
    }
};