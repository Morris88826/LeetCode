/*
48. Rotate Image (https://leetcode.com/problems/rotate-image/description/)

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

ex:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void rotate(vector<vector<int>>& matrix) { // best solution, but too counter-intuitive
        reverse(matrix.begin(), matrix.end()); // clockwise
        // for (auto vi : matrix) reverse(vi.begin(), vi.end()); // if counter-clockwise
        for(int i=0; i<matrix.size()-1; i++){
            for(int j=i+1; j<matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }

    void rotateDepth(vector<vector<int>>& matrix, int layer){
        if(layer>=(matrix.size()/2)){
            return;
        }

        //swap corners first
        int d = matrix.size()-1-layer;
        swap(matrix[layer][layer], matrix[layer][d]);
        swap(matrix[d][layer], matrix[layer][layer]);
        swap(matrix[d][d], matrix[d][layer]);

        for(int i=layer+1; i<=d-1; i++){
            swap(matrix[layer][i], matrix[matrix.size()-1-i][layer]);
            swap(matrix[matrix.size()-1-i][layer], matrix[d][matrix.size()-1-i]);
            swap(matrix[d][matrix.size()-1-i], matrix[i][d]);
        }
        rotateDepth(matrix, layer+1);
    }
    void rotate_v1(vector<vector<int>>& matrix) {
        rotateDepth(matrix, 0);
        return;
    }
};