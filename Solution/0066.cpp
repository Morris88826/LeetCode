/*
66. Plus One (https://leetcode.com/problems/plus-one/description/)

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

ex:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        bool advance = true;
        for(int i=digits.size()-1; i>=0; i--){
            if(advance){
                if(digits[i]+1 == 10){
                    result.insert(result.begin(), 0);
                    advance = true;
                }else{
                    result.insert(result.begin(), digits[i]+1);
                    advance = false;
                }
            }else{
                result.insert(result.begin(), digits[i]);
            }
        }
        if(advance){
            result.insert(result.begin(), 1);
        }
        return result;
    }
};