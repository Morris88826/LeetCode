/*
242. Valid Anagram (https://leetcode.com/problems/valid-anagram/description/)

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) { // just sort the string
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t){
            return true;
        }
        return false;
    }

    bool isAnagram_v1(string s, string t) { // using unordered_map, hash table
        unordered_map<int,int> myMap;
        for(int i=0; i<s.length(); i++){
            if(myMap.find(s[i])==myMap.end()){
                myMap[s[i]] = 0;
            }
            myMap[s[i]] += 1;
        }

        for(int i=0; i<t.length(); i++){
            if(myMap.find(t[i])==myMap.end()){
                return false;
            }
            myMap[t[i]] -= 1;
            if(myMap[t[i]]==0){
                myMap.erase(t[i]);
            }
        }

        if(myMap.size()>0){
            return false;
        }else{
            return true;
        }
    }
};