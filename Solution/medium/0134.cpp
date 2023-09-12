/*
134. Gas Station (https://leetcode.com/problems/gas-station/description/)

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

ex:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0;
        int totalGas = 0;
        int currentGas = 0;
        int start_idx = 0;
        for(int i=0; i<gas.size(); i++){
            currentGas += gas[i] - cost[i];
            if(currentGas<0){
                start_idx = (i+1)%gas.size();
                currentGas = 0;
            }
            totalGas += gas[i];
            totalCost += cost[i];
        }

        return totalGas<totalCost? -1:start_idx; // important: if totalGas >= totalCost, the car can definitely finish the run
    }

    int canCompleteCircuit_bad(vector<int>& gas, vector<int>& cost) { // O(n^2)
        if(gas.size()==1){
            if(gas[0]>=cost[0])
                return 0;
            else
                return -1;
        }
            

        vector<int> remaining;
        for(int i=0; i<gas.size(); i++){
            remaining.push_back(gas[i]-cost[i]);
        }

        int n = gas.size();
        for(int i=0; i<n; i++){
            if(remaining[i]>0){
                int j = (i+1)%n;
                int sum = remaining[i];
                while(j!=i){
                    sum += remaining[j];
                    if(sum<0){
                        break;
                    }
                    j = (j+1)%n;
                }

                if(i==j)
                    return i;
            }
        }
        return -1;
    }
};