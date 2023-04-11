/*
1. Two Sum (https://leetcode.com/problems/two-sum/)

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

ex:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]

Can you come up with an algorithm that is less than O(n2) time complexity?
Hint: use hashmap
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> myMap;
        for(int i=0; i<nums.size(); i++){
            int cur = nums[i];
            // cur + x = target
            // x = target - cur
            int x = target - cur;
            if(myMap.find(x) != myMap.end()){
                return {myMap[x],i};
            }
            myMap[cur] = i;
        }
        return {};
    }

    vector<int> twoSum_v1(vector<int>& nums, int target){
        for(int i=0; i<nums.size(); i++){
            int _diff = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(_diff == nums[j]){
                    return {i,j};
                }
            }
        }
        return {};
    }
};