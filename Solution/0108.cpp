/*
108. Convert Sorted Array to Binary Search Tree (https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)

Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

p.s. A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

ex:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

* 1 <= nums.length <= 104
* -104 <= nums[i] <= 104
* nums is sorted in a strictly increasing order.

Hint: uses binary search, also review on AVL tree (although no need here)
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* search(int p, int q, vector<int>& nums){
        if(p>q){
            return NULL;
        }

        int mid = (p+q)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = search(p, mid-1, nums);
        node->right = search(mid+1, q, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }

        return search(0, nums.size()-1, nums);
    }
};