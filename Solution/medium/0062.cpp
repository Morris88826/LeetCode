/*
62. Unique Paths (https://leetcode.com/problems/unique-paths/description/)

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

ex:
Input: m = 3, n = 7
Output: 28

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int uniquePaths(int m, int n) { // simple dp2, but not as efficient as v1
        
        vector<int> vec(n,1);
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                vec[j] = vec[j+1] + vec[j];
            }
        }
        return vec[0];
    }

    int uniquePaths_v1(int m, int n) { // very fast but have to handle overflow problems
        
        int total = (m-1) + (n-1);

        if(total==0){
            return 1;
        }

        int result = 1;
        if(m>n){
            vector<int> _vec;
            for(int i=n-1; i>1; i--){
                _vec.push_back(i);
            }

            for(int i=total; i>=m; i--){
                result *= i;
                for(int j=0; j<_vec.size(); j++){
                    if(result%_vec[j]==0){
                        result /= _vec[j];
                        _vec.erase(_vec.begin()+j);
                        break;
                    }
                }
            }
            for(int j=0; j<_vec.size(); j++){
                result /= _vec[j];
            }
        }else{
            vector<int> _vec;
            for(int i=m-1; i>1; i--){
                _vec.push_back(i);
            }

            for(int i=total; i>=n; i--){
                result *= i;
                for(int j=0; j<_vec.size(); j++){
                    if(result%_vec[j]==0){
                        result /= _vec[j];
                        _vec.erase(_vec.begin()+j);
                        break;
                    }
                }
            }
            for(int j=0; j<_vec.size(); j++){
                result /= _vec[j];
            }
        }
        return result;
    }
};