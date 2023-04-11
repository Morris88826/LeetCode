/*
136. Single Number (https://leetcode.com/problems/single-number/description/)

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

ex:
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

Hint: XOR
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { // uses the idea of bitwise xor, since there is only one number that appears once and the rest appear twice(can canel each other). A^B^A = A
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        return ans;
    }

    int singleNumber_v1(vector<int>& nums) { // this uses extra O(N) space, not optimal. Also unordered_map is usually faster for lookup
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++){
            auto ptr = myMap.find(nums[i]);
            if(ptr==myMap.end()){
                myMap[nums[i]] = 1;
            }else{
                myMap.erase(ptr);
            }
        }

        return myMap.begin()->first;
    }
};