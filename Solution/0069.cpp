/*
69. Sqrt(x) (https://leetcode.com/problems/sqrtx/description/)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

ex:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

class Solution {
public:
    int mySqrt(int x) {

        int p = 0;
        int q = x;
        while(p<q){
            long mid = (p+q)/2;
            if(mid*mid == x){
                return mid;
            }else if(mid*mid > x){
                q = mid-1;
            }else{
                p = mid+1;
            }
        }

        if(p*p>x){
            return p-1;
        }else{
            return p;
        }
    }
};