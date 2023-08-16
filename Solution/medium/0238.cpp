/*
238. Product of Array Except Self (https://leetcode.com/problems/product-of-array-except-self/description/)

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

ex:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        result.push_back(1);
        for(int i=1; i<nums.size(); i++){
            result.push_back(result[i-1]*nums[i-1]);
        }
        
        int right = 1;
        for(int i=result.size()-1; i>=0; i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }

    vector<int> productExceptSelf_v1(vector<int>& nums) {
        vector<int> result;
        vector<int> result2;
        result.push_back(1);
        result2.push_back(1);
        for(int i=1; i<nums.size(); i++){
            result.push_back(result[i-1]*nums[i-1]);
            result2.push_back(result2[i-1]*nums[nums.size()-i]);
        }

        reverse(result2.begin(), result2.end());

        for(int i=0; i<result.size(); i++){
            result[i] *= result2[i];
        }
        return result;
    }
};