/*
17. Letter Combinations of a Phone Number (https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


*/

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> _letterCombinations(string digits, int start_idx){

        if(start_idx==digits.length()){
            return {""};
        }
        
        vector<string> result;
        vector<string> tmp = _letterCombinations(digits, start_idx+1);
        
        int digit = digits[start_idx]-'0';
        for(int i=0; i<pad[digit].length(); i++){
            string s(1,pad[digit][i]); // we can initialize a string with a char, or we can concat string and char as the following
            // string s = "";
            // s += pad[digit][i];
            for(int j=0; j<tmp.size(); j++){
                result.push_back(s+tmp[j]);
            }
        }
        return result;
    }

    vector<string> letterCombinations_recur(string digits) { // recursize approach
        if(digits.length()==0){
            return {};
        }
        
        return _letterCombinations(digits, 0);
    }

    vector<string> letterCombinations_iter(string digits) { // iterative approach
        if(digits.length()==0){
            return {};
        }
        vector<string> result={""};
        for(int i=0; i<digits.length(); i++){
            int digit = (int)(digits[i]-'0');
            vector<string> tmp;
            for(int j=0; j<pad[digit].length(); j++){
                for(int k=0; k<result.size(); k++){
                    tmp.push_back(result[k]+pad[digit][j]);
                }
            }
            result = tmp;
        }
        return result;
    }
};