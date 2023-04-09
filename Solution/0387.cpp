/*
387. First Unique Character in a String (https://leetcode.com/problems/first-unique-character-in-a-string/description/)

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

ex:
Input: s = "leetcode"
Output: 0

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1
*/
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> myMap;
        for(int i=0; i<s.length(); i++){
            myMap[s[i]] = (myMap.find(s[i])==myMap.end())? i : -1;
        }

        int first = -1;
        for(auto iter = myMap.begin(); iter!=myMap.end(); iter++){
            if(iter->second!=-1){
                first = (first==-1)? iter->second : min(first, iter->second);
            }
        }
        return first;
    }  
};