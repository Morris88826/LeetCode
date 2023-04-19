/*
46. Permutations (https://leetcode.com/problems/permutations/description/)

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

ex:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Input: nums = [1]
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> result;

    void solve(vector<int>& a, int index){
        if(index>=a.size()){
            result.push_back(a);
        }

        for(int i=index; i<a.size(); i++){
            swap(a[i], a[index]);
            solve(a, index+1);
            swap(a[i], a[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) { // most efficient
        solve(nums, 0);
        return result;
    }

    vector<vector<int>> permute_v1(vector<int>& nums) {
        if(nums.size()==1){
            return {{nums[0]}};
        }
        int val = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> output = permute(nums);
        vector<vector<int>> result;
        for(int i=0; i<output.size(); i++){
            for(int j=0; j<output[i].size(); j++){
                vector<int> tmp = output[i];
                tmp.insert(tmp.begin()+j, val);
                result.push_back(tmp);
            }
            output[i].push_back(val);
            result.push_back(output[i]);
        }
        return result;
    }
};