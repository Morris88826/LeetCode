/*
171. Excel Sheet Column Number (https://leetcode.com/problems/excel-sheet-column-number/description/)

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

Ex:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Input: columnTitle = "A"
Output: 1

Input: columnTitle = "AB"
Output: 28

Input: columnTitle = "ZY"
Output: 701
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNum = 0;
        int digits = columnTitle.length();
        for(int i=0; i<digits; i++){
            int val = columnTitle[i]-'A'+1;
            columnNum = 26*columnNum+val;
        }
        return columnNum;
    }

    int titleToNumber_v1(string columnTitle) {
        int columnNum = 0;
        int base = 26;
        int digits = columnTitle.length();
        for(int i=0; i<digits; i++){
            int val = (int)(columnTitle[digits-1-i])-(int)('A')+1;
            columnNum += val*pow(base, i);
        }
        return columnNum;
    }
};