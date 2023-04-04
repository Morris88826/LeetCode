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

Hint: use Divide-and-conquer, beware of overflow issues
*/

class Solution {
public:

    int mySqrt(int x){
        if(x == 0){
            return 0;
        }

        int p = 1;
        int q = x;
        while(p<=q){
            int mid = p + (q-p)/2; // prevent the overflow problem
            if(mid == x/mid){ // prevent the overflow problem
                return mid;
            }else if(mid > x/mid){
                q = mid-1;
            }else{
                p = mid+1;
            }
        }
        return q;
    }

    int mySqrt_v1(int x) { // using long to avoid overflow, but not optimal

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