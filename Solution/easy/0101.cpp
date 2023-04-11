/*
101. Symmetric Tree (https://leetcode.com/problems/symmetric-tree/description/)

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

ex:
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false

Follow up: Could you solve it both recursively and iteratively?

*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_Recur {
public:
    bool isSym(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL){
            return true;
        }else if((l==NULL && r!=NULL)||(l!=NULL && r==NULL)){
            return false;
        }

        return (l->val == r->val)&&isSym(l->left, r->right)&&isSym(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return false;
        }

        return isSym(root->left, root->right);
    }
};


class Solution_Iter { // using the idea of queue
public:
bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return false;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while(!q.empty()){
            TreeNode* n1 = q.front();
            q.pop();
            TreeNode* n2 = q.front();
            q.pop();

            if(n1==NULL&&n2==NULL){
                continue;
            }
            if((n1==NULL&&n2!=NULL)||(n1!=NULL&&n2==NULL)||(n1->val!=n2->val)){
                return false;
            }
            
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);
        }
        return true;
    }
};