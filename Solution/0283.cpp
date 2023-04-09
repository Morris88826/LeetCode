/*
283. Move Zeroes (https://leetcode.com/problems/move-zeroes/description/)

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

ex:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input: nums = [0]
Output: [0]

Could you minimize the total number of operations done?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                int tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;
                start += 1;
            }
        }
        return;
    }
};