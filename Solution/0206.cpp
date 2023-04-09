/*
206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list/description/)

Given the head of a singly linked list, reverse the list, and return the reversed list.

ex:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

    ListNode* reverseList_recur(ListNode* head) { // recursive method
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* cur = reverseList_recur(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }

    ListNode* reverseList_iter(ListNode* head) { // iterative method
        if(head==NULL){
            return NULL;
        }
        
        // reverse iteratively
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur!=NULL){
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }
        return prev;
    }
};