/*
191. Number of 1 Bits (https://leetcode.com/problems/number-of-1-bits/description/)

Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

ex:
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
*/

#include <iostream>

class Solution {
public:

    int hammingWeight(uint32_t n) { // cool solution
        int num =0;
        while(n!=0){
            n &= (n-1);
            num += 1;
        }
        return num;
    }

    int getHeight(uint32_t n, int depth, uint32_t p){
        if(depth == 0){
            return n;
        }
        int l = getHeight(n >> depth, depth/2, p>>depth/2);
        int r = getHeight(n&p, depth/2, p>>depth/2);

        return l + r;
    }

    int hammingWeight_v2(uint32_t n) { // can also use divide and conquer
        return getHeight(n, 16, 0x0000ffff);
    }

    int hammingWeight_v1(uint32_t n) { // O(logN)
        int num = 0;
        while(n!=0){
            if(n%2==1){
                num += 1;
            }
            n = n>>1;
        }
        return num;
    }
};