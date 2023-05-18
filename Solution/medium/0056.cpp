/*
56. Merge Intervals (https://leetcode.com/problems/merge-intervals/description/)

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

ex:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        
        sort(intervals.begin(),
          intervals.end(),
          [] (const vector<int> &a, const vector<int> &b)
          {
              return a[0] < b[0];
          });
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=result[result.size()-1][1]){
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};