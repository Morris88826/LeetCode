/*
202. Happy Number (https://leetcode.com/problems/happy-number/description/)

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

ex:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Input: n = 2
Output: false

*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumOfSquareDigits(int n){
        int result = 0;
        while(n!=0){
            int mod = (n%10);
            result += mod*mod;
            n /= 10;
        }
        return result;
    }

    bool isHappy(int n) { // similar idea as finding cycle linked list
        int slow = sumOfSquareDigits(n);
        int fast = sumOfSquareDigits(slow);
        while(fast!=1){
            if(slow==fast){
                return false;
            }
            slow = sumOfSquareDigits(slow);
            fast = sumOfSquareDigits(sumOfSquareDigits(fast));
        }
        return true;
    }
    
    bool isHappy_v1(int n) {
        unordered_map<int,int> myMap;
        while(n!=1){
            if(myMap.find(n) != myMap.end()){
                return false;
            }   
            myMap[n] = 1;
            n = sumOfSquareDigits(n);
        }
        return true;
    }
};