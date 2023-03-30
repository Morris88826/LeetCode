/*
21. Merge Two Sorted Lists (https://leetcode.com/problems/merge-two-sorted-lists/description/)

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

ex:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Hint: can use recursion
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>  
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    // recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL){
            return list2;
        }else if(list2==NULL){
            return list1;
        }

        ListNode* cur;
        if(list1->val<=list2->val){
            cur = list1;
            cur->next = mergeTwoLists(list1->next, list2);
        }else{
            cur = list2;
            cur->next = mergeTwoLists(list1, list2->next);
        }
        return cur;
    }

    // iterative approach
    ListNode* mergeTwoLists_v1(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }else if(list2 == NULL){
            return list1;
        }

        ListNode* head;
        if(list1->val<=list2->val){
            head = list1;
            list1 = list1->next;
        }else{
            head = list2;
            list2 = list2->next;
        }
        ListNode* cur = head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if(list1!=NULL){
            cur->next = list1;
        }else if(list2!=NULL){
            cur->next = list2;
        }

        return head;
    }
};