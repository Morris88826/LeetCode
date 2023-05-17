/*
54. Spiral Matrix (https://leetcode.com/problems/spiral-matrix/description/)

Given an m x n matrix, return all elements of the matrix in spiral order.

ex:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> result;
        while(result.size()<(m*n)){
            for(int j=left; j<right+1; j++){
                result.push_back(matrix[top][j]);
            }
            top += 1;
            for(int j=top; j<bottom+1; j++){
                result.push_back(matrix[j][right]);
            }
            right -= 1;

            if(top<=bottom){
                for(int j=right; j>=left; j--){
                    result.push_back(matrix[bottom][j]);
                }
                bottom -= 1;
            }

            if(left<=right){
                for(int j=bottom; j>=top; j--){
                    result.push_back(matrix[j][left]);
                }
                left += 1;
            }
        }

        return result;
    }

    vector<int> spiralOrder_v1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result;

        for(int i=0; i<((float)m/2.0); i++){
            for(int j=i; j<n-i; j++){
                result.push_back(matrix[i][j]);
            }
            if(result.size()==(m*n)){
                return result;
            }

            for(int j=(i+1); j<m-i; j++){
                result.push_back(matrix[j][n-i-1]);
            }

            if(result.size()==(m*n)){
                return result;
            }

            for(int j=(n-i-2); j>=i; j--){
                result.push_back(matrix[m-i-1][j]);
            }
            if(result.size()==(m*n)){
                return result;
            }

            for(int j=(m-i-2); j>=i+1; j--){
                result.push_back(matrix[j][i]);
            }
            if(result.size()==(m*n)){
                return result;
            }
        }
        return result;
    }
};