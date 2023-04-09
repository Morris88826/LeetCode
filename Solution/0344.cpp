/*
344. Reverse String (https://leetcode.com/problems/reverse-string/description/)

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

ex:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        for(int i=0; i<length/2; i++){
            swap(s[i], s[length-1-i]);
        }
        return;
    }
};