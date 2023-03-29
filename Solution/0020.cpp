'''
20. Valid Parentheses (https://leetcode.com/problems/valid-parentheses/)

Given a string s containing just the characters \'(\', \')\', \'{\', \'}\', \'[\' and \']\', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

ex:
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Hint: Using stack
'''

class Solution {
public:
    bool isValid(string s) {
        map<char,char> myMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        vector<char> v;
        for(int i=0; i<s.length(); i++){
            if(s[i]==')'||s[i]==']'||s[i]=='}'){
                if(v.size()==0){
                    return false;
                }else{
                    if(v[v.size()-1] == myMap[s[i]]){
                        v.pop_back();
                    }else{
                        return false;
                    }
                }
            }else{
                v.push_back(s[i]);
            }
        }

        if(v.size()==0){
            return true;
        }else{
            return false;
        }
    }

    bool isValidPractice(string s) {
        
    }
};