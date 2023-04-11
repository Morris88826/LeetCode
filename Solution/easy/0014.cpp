/*
14. Longest Common Prefix (https://leetcode.com/problems/longest-common-prefix/description/)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

ex:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Hint: Can use sort 
*/

#include <iostream>  
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result = "";
        sort(strs.begin(), strs.end()); // Since is sorted, if you have 'fl' in the first string, having 'fl' in the last string means that all the in-between strings also have 'fl'. So you pretty much can only compare these two and ignore the rest.
        string n = strs[0];
        string m = strs[strs.size()-1];
        for(int i=0; i<n.length(); i++){
            if(n[i]==m[i]){
                result += n[i];
            }else{
                break;
            }
        }
        return result;
    }

    string longestCommonPrefix_v1(vector<string>& strs) {
        
        string result = "";
        int i = 0;

        int maxLength = 0;
        for(int j=0; j<strs.size();j++){
            if(strs[j].length() > maxLength){
                maxLength = strs[j].length();
            }
        }

        while(i<maxLength){
            for(int j=0; j<strs.size(); j++){
                if(j==(strs.size()-1)){
                    result += strs[j][i];
                    i += 1;
                }else{
                    if(strs[j][i]!=strs[j+1][i]){
                        return result;
                    }
                }
            }
        }
        return result;
    }
};