/*
26. Remove Duplicates from Sorted Array (https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

ex: 

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

# Hint: Find non-repetitive elements and move them to their desired index.

*/
#include <iostream>  
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //fastest
        int k = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[k-1]!=nums[i]){
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }

    int removeDuplicates_v1(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size();i++){
            if(i==0){
                result.push_back(nums[i]);
            }else{
                if(nums[i]!=result[result.size()-1]){
                    result.push_back(nums[i]);
                }
            }
        }
        nums = result;
        return result.size();
    }

    int removeDuplicates_v2(vector<int>& nums) {
        int k = nums.size();
        for(int i=1; i<nums.size(); ){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin() + i);
                k -= 1;
            }else{
                i += 1;
            }
        }
        return k;
    }
};