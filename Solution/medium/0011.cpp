/*
11. Container With Most Water (https://leetcode.com/problems/container-with-most-water/)

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

ex:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Input: height = [1,1]
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) { // two pointers
        int result = 0;
        int i = 0;
        int j = height.size()-1;

        while(i<j){
            if(height[i]>height[j]){ // we don't need to search for index > i since no matter what index that larger than i, the volumne will be smaller
                result = max(result, (j-i)*height[j]);
                j -= 1;
            }else if(height[i]<height[j]){
                result = max(result, (j-i)*height[i]);
                i += 1;
            }else{
                result = max(result, (j-i)*height[i]);
                i += 1;
                j -= 1;
            }
        }
        return result;
    }

    int maxArea_v1(vector<int>& height) { // naive approach
        int result = 0;
        int n = height.size();
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<i; j++){
                int vol = min(height[i], height[j])*(i-j);
                if(vol>result){
                    result = vol;
                }
            }
        }
        return result;
    }
};