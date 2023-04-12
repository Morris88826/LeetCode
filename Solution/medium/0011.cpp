/*
11. Container With Most Water
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) { // two pointers
        int result = 0;
        int i = 0;
        int j = height.size()-1;

        while(i<j){
            if(height[i]>height[j]){ // we don't need to search for index > i since no matter what index that larger than i, the volumne will be smaller
                result = max(result, (j-i)*height[j]);
                j -= 1;
            }else if(height[i]<height[j]){
                result = max(result, (j-i)*height[i]);
                i += 1;
            }else{
                result = max(result, (j-i)*height[i]);
                i += 1;
                j -= 1;
            }
        }
        return result;
    }

    int maxArea_v1(vector<int>& height) { // naive approach
        int result = 0;
        int n = height.size();
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<i; j++){
                int vol = min(height[i], height[j])*(i-j);
                if(vol>result){
                    result = vol;
                }
            }
        }
        return result;
    }
};