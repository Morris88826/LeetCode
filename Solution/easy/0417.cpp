/*
412. Fizz Buzz (https://leetcode.com/problems/fizz-buzz/description/)

Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

ex:
Input: n = 3
Output: ["1","2","Fizz"]

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i=1; i<=n; i++){
            if(i%3==0 && i%5==0){
                result.push_back("FizzBuzz");
            }else if(i%3==0){
                result.push_back("Fizz");
            }else if(i%5==0){
                result.push_back("Buzz");
            }else{
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};