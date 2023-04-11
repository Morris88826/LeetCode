/*
217. Contains Duplicate (https://leetcode.com/problems/contains-duplicate/description/)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

ex:
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                return true;
            }
        }
        return false;
    }

    // Time Complexity: O(n)
    bool containsDuplicate_v1(vector<int>& nums) { //using unordered map, average time complexity = O(1), worst case O(n)
        unordered_map<int,int> myMap;
        for(int i=0; i<nums.size(); i++){
            if(myMap.find(nums[i])!=myMap.end()){
                return true;
            }
            myMap[nums[i]] = 1;
        }
        return false;
    }
};