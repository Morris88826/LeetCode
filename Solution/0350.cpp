/*
350. Intersection of Two Arrays II (https://leetcode.com/problems/intersection-of-two-arrays-ii/description/)

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

ex:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
-> we can select sub-arrays and find their intersection. What's left behind (not having intersection) will be added to other sub-arrays so that it keeps comparing
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> intersect_v2(vector<int>& nums1, vector<int>& nums2) { // if nums1.size() << nums2.size(), use this method, as it uses less space
        vector<int> intersect;
        unordered_map<int,int> myMap;

        for(int i=0; i<nums1.size(); i++){
            if(myMap.find(nums1[i])==myMap.end()){
                myMap[nums1[i]] = 0;
            }
            myMap[nums1[i]] += 1;
        }

        for(int i=0; i<nums2.size(); i++){
            if(myMap.find(nums2[i])!=myMap.end()){
                intersect.push_back(nums2[i]);
                myMap[nums2[i]] -= 1;
                if(myMap[nums2[i]]==0){
                    myMap.erase(nums2[i]);
                }
            }
        }
        
        return intersect;
    }

    vector<int> intersect_v1(vector<int>& nums1, vector<int>& nums2) { // if already sorted, use this one (skip the sort part)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersect;
        int i = 0;
        int j = 0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i += 1;
            }else if(nums1[i]>nums2[j]){
                j += 1;
            }else{
                intersect.push_back(nums1[i]);
                i += 1;
                j += 1;
            }
        }
        return intersect;
    }
};