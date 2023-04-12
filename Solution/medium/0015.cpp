/*
15. 3Sum (https://leetcode.com/problems/3sum/description/)

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Hint: using two pointers and also set to remove duplicates
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> mySet;
        for(int i=0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    mySet.insert({nums[i], nums[j], nums[k]});
                    j += 1;
                    k -= 1;
                }else if(sum>0){
                    k -= 1;
                }else{
                    j += 1;
                }
            }
        }

        vector<vector<int>> result;
        for(auto iter=mySet.begin(); iter!=mySet.end(); iter++){
            result.push_back(*iter);
        }
        return result;
    }
};