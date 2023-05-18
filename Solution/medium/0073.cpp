/*
73. Set Matrix Zeroes (https://leetcode.com/problems/set-matrix-zeroes/description/)

Companies
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void setZeroes_best(vector<vector<int>>& matrix) { // best approach

        bool firstRowEmpty = false;
        bool firstColEmpty = false;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        firstRowEmpty = true;
                    }
                    if(j==0){
                        firstColEmpty = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowEmpty){
            for(int i=0; i<matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(firstColEmpty){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }

    void setZeroes_const(vector<vector<int>>& matrix) { // const space but quite stupid to search for unique number
        int target = INT_MIN;
        bool found = false;

        while(found==false){
            bool repeated = false;
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[0].size(); j++){
                    if(target==matrix[i][j]){
                        repeated = true;
                        break;
                    }
                }
                if(repeated){
                    break;
                }
            }
            if(repeated){
                target += 1;
            }else{
                found = true;
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    // row set to 0
                    for(int k=0; k<matrix[0].size(); k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k] = target;
                        }
                    }

                    for(int k=0; k<matrix.size(); k++){
                        if(matrix[k][j] != 0){
                            matrix[k][j] = target;
                        }
                    }
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==target){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void setZeroes_v1(vector<vector<int>>& matrix) { // O(m*n) space
        
        // 2d matrix method
        vector<vector<int>> table; 
        for(int i=0; i<matrix.size(); i++){
            vector<int> _vec(matrix[0].size(), 1);
            table.push_back(_vec);
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    for(int k=0; k<matrix[0].size(); k++){
                        table[i][k] = 0;
                    }
                    for(int k=0; k<matrix.size(); k++){
                        table[k][j] = 0;
                    }
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[i][j] = matrix[i][j] * table[i][j];
            }
        }
    }

    void setZeroes_v2(vector<vector<int>>& matrix) { // O(m+n) space
        vector<int> emptyRow;
        vector<int> emptyCol;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    emptyRow.push_back(i);
                    emptyCol.push_back(j);
                }
            }
        }

        for(int i=0; i<emptyRow.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[emptyRow[i]][j] = 0;
            }
        }

        for(int i=0; i<emptyCol.size(); i++){
            for(int j=0; j<matrix.size(); j++){
                matrix[j][emptyCol[i]] = 0;
            }
        }
    }
};