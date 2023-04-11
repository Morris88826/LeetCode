/*
2. Add Two Numbers (https://leetcode.com/problems/add-two-numbers/description/)

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

ex:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(l1!=NULL||l2!=NULL){
            int v1 = l1==NULL? 0: l1->val;
            int v2 = l2==NULL? 0: l2->val;
            int val = v1 + v2 + carry;
            carry = val/10;
            val %= 10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1==NULL? NULL: l1->next;
            l2 = l2==NULL? NULL: l2->next;
        }

        if(carry){
            cur->next = new ListNode(1);
        }
        return head->next;
    }


    ListNode* addTwoNumber(ListNode* l1, ListNode* l2, int carry){
        ListNode* head = NULL;
        if(l1==NULL && l2==NULL){
            if(carry){
                head = new ListNode(carry);
            }
            return head;
        }

        ListNode* node;
        head = new ListNode((l1==NULL? 0:l1->val) + (l2==NULL? 0:l2->val) + carry);
        if(head->val>=10){
            head->val -= 10;
            carry = 1;
        }else{
            carry = 0;
        }
        node = addTwoNumber(l1==NULL? NULL: l1->next, l2==NULL? NULL: l2->next, carry);
        head->next = node;
        return head;
    }
    ListNode* addTwoNumbers_v1(ListNode* l1, ListNode* l2) {
        return addTwoNumber(l1, l2, false);
    }
};