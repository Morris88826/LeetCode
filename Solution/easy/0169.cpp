/*
169. Majority Element (https://leetcode.com/problems/majority-element/description/)

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

ex:
Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int majorityElement(vector<int>& nums) { // fastest: O(n), also O(1) space
        int lead = nums[0]; // since nums.size()>=1
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(count == 0){
                lead = nums[i];
            }
            count += (nums[i]==lead)? 1: -1;
        }
        return lead;
    }

    int majorityElement_raw(vector<int>& nums) { // O(n), same but not as clean as the approach above
        int counter = 0;
        int lead = nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(counter == 0){
                lead = nums[i];
                counter += 1;
            }else{
                if(lead == nums[i]){
                    counter += 1;
                }else{
                    counter -= 1;
                }
            }
        }
        return lead;
    }

    int majorityElement_v1(vector<int>& nums) { // O(nlogn) runtime, O(1) space
        sort(nums.begin(), nums.end());
        int m = nums.size()/2;
        return nums[m];
    }
};