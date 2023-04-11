/*
326. Power of Three (https://leetcode.com/problems/power-of-three/description/)

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

ex:
Input: n = 27
Output: true
Explanation: 27 = 33

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

*/
#include <iostream>
#include <cmath>

class Solution {
public:

    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        return (1162261467 % n)==0? true: false;
    }

    bool isPowerOfThree_recur(int n) {
        if(n==1){
            return true;
        }else if(n<=0||n%3!=0){
            return false;
        }
        return isPowerOfThree_recur(n/3);
    }

    bool isPowerOfThree_iter(int n) {
        while(n>0){
            if(n==1){
                return true;
            }
            else if(n%3!=0){
                return false;
            }
            n = n/3;
        }
        return false;
    }

    bool isPowerOfThree_v1(int n) {
        if(n<=0){
            return false;
        }

        int r = round(log(n)/log(3));
        if(pow(3,r)==n){
            return true;
        }else{
            return false;
        }
    }
};