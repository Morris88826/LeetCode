/*
45. Jump Game II (https://leetcode.com/problems/jump-game-ii/description/)

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

ex:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [2,3,0,1,4]
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        // record the max position that having i-th elements can reach to, don't need to worry if not reaching the end
        for(int i=1; i<nums.size(); i++){
            nums[i] = max(nums[i]+i, nums[i-1]);
        } 

        int ind = 0;
        int numJump = 0;
        while(ind<nums.size()-1){
            ind = nums[ind];
            numJump += 1;
        }
        return numJump;
    }

    int jump_v1(vector<int>& nums) {
        if(nums.size()==1)
            return 0;

        vector<int> minStep;
        minStep.push_back(0);
        for(int i = nums.size()-2; i>=0; i--){
            int _min = minStep[nums.size()-1-i-1];
            if(nums[i]+i<nums.size()){
                for(int j=0; j<min((int)minStep.size(), nums[i]); j++){
                    if(_min>minStep[minStep.size()-1-j]){
                        _min = minStep[minStep.size()-1-j];
                    }
                }
            }else{
                _min = 0;
            }
            minStep.push_back(_min+1);
        }
        return minStep[minStep.size()-1];
    }

    int jump_v2(vector<int>& nums) {
                int n = nums.size();
        if(n==1)
            return 0;

        vector<int> minSteps; // minStep[i] => the min step to get from index n-1-i to n-1
        minSteps.push_back(0);
        for(int i=n-2; i>=0; i--){
            if(nums[i]+i>=n-1){ // check if can reach the end
                minSteps.push_back(1);
            }else if(nums[i]==0){ // check if cannot reach the end, minStep = INT_MAX
                minSteps.push_back(INT_MAX);
            }else{
                int minStep = minSteps[minSteps.size()-1];
                for(int j=1; j<nums[i]; j++){
                    if(minStep>minSteps[minSteps.size()-1-j])
                        minStep = minSteps[minSteps.size()-1-j];
                }
                if(minStep == INT_MAX) // minStep == INT_MAX -> cannot reach the end, set max
                    minSteps.push_back(minStep);
                else
                    minSteps.push_back(minStep+1);
            }
        }
        return minSteps[minSteps.size()-1];
    }
};
