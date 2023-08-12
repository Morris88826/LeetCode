/*
121. Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

ex:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) { // buy at previous' lowest 
        if(prices.size()==1){
            return 0;
        }

        int lowest = INT_MAX;
        int profit = 0;
        int maxP = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<lowest){
                lowest = prices[i];
            }

            profit = prices[i] - lowest;
            if(maxP<profit){
                maxP = profit;
            }
        }
        return maxP;
    }

    int maxProfit_v3(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }

        int minIdx = 0;
        int maxIdx = 0;
        int maxP = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<prices[minIdx]){
                minIdx = i;
                maxIdx = i;
            }
            else if(prices[i]>prices[maxIdx]){
                maxIdx = i;
            }

            int profit = prices[maxIdx]-prices[minIdx];
            if(profit>maxP){
                maxP = profit;
            }
        }
        return maxP;
    }

    int maxProfit_v2(vector<int>& prices) { // faster, no need to have additional vector to store the DP result
        if(prices.size()==1){
            return 0;
        }

        int prev = 0;
        int maxP = 0;
        for(int i=1; i<prices.size(); i++){
            int p = prices[i]-prices[i-1];
            int profit = max(p, prev+p);
            if(profit>maxP){
                maxP = profit;
            }
            prev = profit;
        }
        return maxP;
    }

    int maxProfit_v1(vector<int>& prices) { // using dynamic programming
        if(prices.size()==1){
            return 0;
        }

        vector<int> profits;
        profits.push_back(0);
        int maxP = 0;
        for(int i=1; i<prices.size(); i++){
            int profit = prices[i] - prices[i-1];
            profits.push_back(max(profit, profits[i-1]+profit));
            if(profits[i]>maxP){
                maxP = profits[i];
            }
        }
        return maxP;
    }
};