/*
50. Pow(x, n) (https://leetcode.com/problems/powx-n/description/)

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

ex:
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

constraint:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
-104 <= xn <= 104
*/

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {

        // handle border cases
        if(n==INT_MAX){
            return x==1? 1: x==-1? -1:0;
        }else if(n==INT_MIN){
            return (x==1 || x==-1)? 1:0;
        }

        if(x==0){
            return x;
        }else if(n==0){
            return 1;
        }

        if(n<0){
            x = 1/x;
            n = abs(n);
        }

        bool isNegative = false;
        if(x<0 && n%2!=0){
            isNegative = true;
            x = abs(x);
        }

        double result = x;
        double remainder = 1;
        while(n/2>=1){
            if(result==0){
                return 0;
            }

            if(n%2!=0){
                remainder = remainder*result;
                n -= 1;
            }
            result = result*result;
            n /= 2;
        }
        result *= remainder;
        return (isNegative)? -1*result: result;
    }
};