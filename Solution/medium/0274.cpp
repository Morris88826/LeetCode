/*
274. H-Index (https://leetcode.com/problems/h-index/description/)

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

ex:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Input: citations = [1,3,1]
Output: 1

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int h = 0;
        for(int i=0; i<citations.size(); i++){
            int h1 = citations[i];
            int h2 = citations.size()-i;
            if(min(h1,h2)>h)
                h = min(h1, h2);
        }
        return h;
    }
};