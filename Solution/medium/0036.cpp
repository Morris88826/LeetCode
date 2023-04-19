/*
36. Valid Sudoku (https://leetcode.com/problems/valid-sudoku/description/)

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) { // interesting idea -> use different types to encode to differentiate
        
        unordered_map<string, int> myMap;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }

                string s(1,board[i][j]);
                string key = "(" + s + ")";
                string key1 = to_string(i) + key;
                string key2 = key + to_string(j);
                string key3 = to_string(i/3) + key + to_string(j/3);
                
                if(myMap.find(key1)!=myMap.end() || myMap.find(key2)!=myMap.end() || myMap.find(key3)!=myMap.end()){
                    return false;
                }
                myMap[key1] = 1;
                myMap[key2] = 1;
                myMap[key3] = 1;
            }
        }
        return true;
    }

    bool isValidSudoku_v1(vector<vector<char>>& board) {
        
        bool result = true;

        unordered_map<char,int> rowMap;
        unordered_map<char,int> columnMap;
        unordered_map<char,int> gridMap;
        for(int i=0; i<9; i++){
            rowMap.clear();
            columnMap.clear();
            gridMap.clear();
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && rowMap.find(board[i][j])!=rowMap.end()){
                    return false;
                }

                if(board[j][i]!='.' && columnMap.find(board[j][i])!=columnMap.end()){
                    return false;
                }

                int _row = (i/3)*3 + j/3;
                int _col = (i%3)*3 + j%3;
                if(board[_row][_col]!='.' && gridMap.find(board[_row][_col])!=gridMap.end()){
                    return false;
                }
                rowMap[board[i][j]] = 1;
                columnMap[board[j][i]] = 1;
                gridMap[board[_row][_col]] = 1;
            }
        }
        return true;
    }
};