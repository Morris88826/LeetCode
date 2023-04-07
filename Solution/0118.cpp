/*
118. Pascal's Triangle (https://leetcode.com/problems/pascals-triangle/description/)

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

ex:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Input: numRows = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) { // fastest, don't need to iterate for whole row. Just iterate half of the inner loop as the second half of the row has the same value as the first half but in reverse 
        vector<vector<int>> result;
        for(int i=0; i<numRows; i++){
            if(i==0){
                result.push_back({1});
            }else{
                vector<int> row;
                for(int j=0; j<=i/2; j++){
                    if(j==0){
                        row.push_back(1);
                    }else if(j==i){
                        row.push_back(1);
                    }else{
                        row.push_back(result[i-1][j-1]+result[i-1][j]);
                    }
                }

                result.push_back(row);
                if(i%2==0){
                    row.pop_back();
                }
                reverse(row.begin(), row.end());
                result[i].insert(result[i].end(), row.begin(), row.end());
            }
        }
        return result;
    }

    vector<vector<int>> generate_v1(int numRows) {
        vector<vector<int>> result;
        for(int i=0; i<numRows; i++){
            vector<int> row;
            for(int j=0; j<=i; j++){
                if(j==0){
                    row.push_back(1);
                }else if(j==i){
                    row.push_back(1);
                }else{
                    row.push_back(result[i-1][j-1]+result[i-1][j]);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};