/*
94. Binary Tree Inorder Traversal (https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Preorder: mid -> left -> right
Inorder: left -> mid -> right
Postorder: left -> right -> mid

Input: root = [1,null,2,3]
Output: [1,3,2]

Input: root = []
Output: []

Input: root = [1]
Output: [1]
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

    void traverse(TreeNode* root, vector<int>& vec){
        if(root==NULL){
            return;
        }
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) { // reduce the space used
        vector<int> result;
        traverse(root, result);
        return result;
    }

    vector<int> inorderTraversal_v1(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<int> left = inorderTraversal(root->left);
        int mid = root->val;
        vector<int> right = inorderTraversal(root->right);

        vector<int> result;
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(mid);  
        result.insert(result.end(), right.begin(), right.end());
        
        return result;
    }
};