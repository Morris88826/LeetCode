/*
38. Count and Say (https://leetcode.com/problems/count-and-say/description/)

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = 1
countAndSay(n) is the way you would say the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you say a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string 3322251:

ex:
Input: n = 1
Output: 1

Input: n = 4
Output: 1211
Explanation:
countAndSay(1) = 1
countAndSay(2) = say 1 = one 1 = 11
countAndSay(3) = say 11 = two 1s = 21
countAndSay(4) = say 21 = one 2 + one 1 = 12 + 11 = 1211


Explanation: This is the base case.

int to string -> use to_string(val);
char to string -> use string s(1,char);
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
   string countAndSay(string s){
        string result = "";
        s += " ";
        char c = s[0];
        int count = 1;
        for(int i=1; i<s.size(); i++){
            if(s==" "){
                break;
            }

            if(s[i]!=c){
                result += (to_string(count) + c);
                c = s[i];
                count = 1;
            }else{
                count += 1;
            }
        }
       return result;
    }
    string countAndSay(int n) {
        string s = to_string(1);
        for(int i=1; i<n; i++){
            s = countAndSay(s);
        }
        return s;
    }
};