/*
29. Divide Two Integers (https://leetcode.com/problems/divide-two-integers/description/)

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

ex:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
          return 1;
        }

        bool isPositive = (dividend<0)==(divisor<0);
        unsigned int m = abs(dividend);
        unsigned int n = abs(divisor);
        unsigned int result = 0;
        while(m>=n){
            short i = 0;
            while((n<<(i+1))<m){
                i += 1;
            }
            m -= n<<i;
            result += 1<<i;
        }

        if(result==1<<31 && isPositive){ // (INT_MIN/-1)
            return INT_MAX;
        }


        return isPositive? result:-result;
    }
};