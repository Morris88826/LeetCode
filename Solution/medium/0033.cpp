/*
33. Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

ex:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) { // cleaner ver
        int i =0;
        int j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(target==nums[i]){
                return i;
            }else if(target==nums[j]){
                return j;
            }else if(target==nums[mid]){
                return mid;
            }

            if(nums[i]<nums[mid]){  // no rotation happens on the left
                if(nums[i]<target && target<nums[mid]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }else{ 
                if(nums[mid]<target && target<nums[j]){
                    i = mid + 1;
                }else{
                    j = mid - 1;
                }
            }
        }
        return -1;
    }

    int search_v1(vector<int>& nums, int target) {
        if(nums.size()==1){
            return nums[0]==target? 0: -1;
        }
        int i =0;
        int j = nums.size()-1;
        while(i<j){
            int mid = (i+j)/2;
            if(target==nums[i]){
                return i;
            }else if(target==nums[j]){
                return j;
            }else if(target==nums[mid]){
                return mid;
            }

            if(nums[i]>nums[mid]){
                if(target<nums[mid] || target>nums[i]){ // rotation happens on the left
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }else if(nums[mid]>nums[j]){ // rotation happens on the right
                if(target>nums[mid] || target<nums[j]){
                    i = mid+1;
                }else{
                    j = mid-1;
                }
            }else{ // no rotation within the range
                if(nums[mid]<target){
                    i = mid+1;
                }else{
                    j = mid-1; 
                }
            }
        }
        return -1;
    }
};