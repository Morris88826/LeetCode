/* 70. Climbing Stairs (https://leetcode.com/problems/climbing-stairs/description/)
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

ex:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Hint: Dynamic Programming
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int result = 0;
        int p = 1;
        int pp = 0;
        for(int i=0; i<n; i++){
            result = p + pp;
            pp = p;
            p = result;
        }
        return result;
    }

    int climbStairs_Recur(int n){ // this uses recursion, but it will exceed the time limit as it calculate the same value repeatedly, can use Memoization to prevent this from happening (but need extra space)
        if(n==0 || n==1){
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }


    // This approach uses Memoization to prevent repeated calculation
    int findWays(int n, vector<int>& vec){
        if(n==0 || n==1){
            vec[n] = 1;
            return 1;
        }
        if(vec[n]!=-1){
            return vec[n];
        }
        vec[n] = findWays(n-1, vec) + findWays(n-2, vec);
        return vec[n];
    }
    int climbStairs_Memoization(int n){
        vector<int> vec(n+1,-1);
        return findWays(n, vec);
    }
};