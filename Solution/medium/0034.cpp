/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

ex:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int>& nums, int i, int j, int target){ // it's like sort target in the correct order of nums (sort target to the front if the values are the same)
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]<target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) { // more concise
        if(nums.size()==0){
            return {-1,-1};
        }

        int l = lowerBound(nums, 0, nums.size()-1, target);
        int r = lowerBound(nums, 0, nums.size()-1, target+1)-1;

        if(l<nums.size() && nums[l]==target){
            return {l, r};
        }
        return {-1,-1};
    }

    vector<int> searchRange_v1(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int i = 0;
        int j = nums.size()-1;

        int l = j+1;
        int r = i-1; 
        int mid = -1;
        while(i<=j){ // check if mid equals target
            mid = (i+j)/2;
            if(target==nums[i]){
                l = min(i,l);
            }
            if(target==nums[j]){
                r = max(j,r);
            }

            if(target>nums[mid]){
                i = mid+1;
            }else if(target<nums[mid]){
                j = mid-1;
            }else{
                l = min(mid, l);
                r = max(mid, r);
                break;
            }
        }

        // left 
        int p = i;
        int q = mid;
        while(p<=q){
            int _mid = (p+q)/2;
            if(nums[_mid]==target){
                l = min(_mid, l);
                q = _mid-1;
            }else if(nums[_mid]<target){
                p = _mid+1;
            }else{
                q = _mid-1;
            }
        }

        // right
        p = mid;
        q = j;
        while(p<=q){
            int _mid = (p+q)/2;
            if(nums[_mid]==target){
                r = max(r, _mid);
                p = _mid+1;
            }else if(nums[_mid]<target){
                p = _mid+1;
            }else{
                q = _mid-1;
            }
        }

        l = (l==nums.size())? -1: l;
        return {l, r};
    }
};