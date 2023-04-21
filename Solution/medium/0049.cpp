/*
49. Group Anagrams (https://leetcode.com/problems/group-anagrams/description/)

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Input: strs = [""]
Output: [[""]]

Input: strs = ["a"]
Output: [["a"]]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string,int> myMap;
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(myMap.find(s)==myMap.end()){
                myMap[s] = myMap.size();
                result.push_back({strs[i]});
            }else{
                result[myMap[s]].push_back(strs[i]);
            }
        }

        return result;
    }
};