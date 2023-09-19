/*
59. Spiral Matrix II (https://leetcode.com/problems/spiral-matrix-ii/description/)

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

ex:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Input: n = 1
Output: [[1]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        pair<int, int> top_left = {0,0};
        pair<int, int> top_right = {n-1,0};
        pair<int, int> bottom_right = {n-1,n-1};
        pair<int, int> bottom_left = {0,n-1};

        vector<vector<int>> result(n, vector<int>(n, 0));

        int j = 1;
        while(top_left.first<top_right.first && top_left.second<bottom_left.second){
            // top 
            for(int i=top_left.first; i<top_right.first; i++){
                result[top_left.second][i] = j;
                j += 1;
            }
            // right
            for(int i=top_right.second; i<bottom_right.second; i++){
                result[i][top_right.first] = j;
                j += 1;
            }

            // bottom 
            for(int i=bottom_right.first; i>bottom_left.first; i--){
                result[bottom_right.second][i] = j;
                j += 1;
            }

            // left
            for(int i=bottom_left.second; i>top_left.second; i--){
                result[i][bottom_left.first] = j;
                j += 1;
            }

            top_left.first += 1;
            top_right.first -= 1;

            top_right.second += 1;
            bottom_right.second -= 1;

            bottom_right.first -= 1;
            bottom_left.first += 1;

            bottom_left.second -= 1;
            top_left.second += 1;
        }

        if(top_left.first == top_right.first && top_left.second == top_right.second){
            result[top_left.second][top_left.first ] = j;
        }
        return result;
    }
};