/*
55. Jump Game (https://leetcode.com/problems/jump-game/description/)

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

ex:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> table(nums.size(), false);
        for(int i=nums.size()-1; i>=0; i--){
            int dist = nums.size()-1-i;
            if(nums[i]>=dist){
                table[i] = true;
            }else{
                for(int j=nums[i]; j>0; j--){
                    if(table[i+j] == true){
                        table[i] = true;
                        break;
                    }
                }
            }
        }
        return table[0];
    }
};
