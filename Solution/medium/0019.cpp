/*
19. Remove Nth Node From End of List 

Given the head of a linked list, remove the nth node from the end of the list and return its head.

ex:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

Follow up: Could you do this in one pass?
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

    ListNode* removeNthFromEnd(ListNode* head, int n) { // one pass
        
        ListNode* ahead = head;
        for(int i=0; i<n; i++){
            ahead = ahead->next;
        }

        ListNode* cur = head;
        if(ahead==NULL){
            return cur->next;
        }
    
        while(ahead!=NULL){
            if(ahead->next==NULL){
                cur->next = cur->next->next;
                break;
            }
            ahead = ahead->next;
            cur = cur->next;
        }
        return head;
    }

    ListNode* removeNthFromEnd_v1(ListNode* head, int n) { // two pass
        int length = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            length += 1;
            cur = cur->next;
        }
        
        int remove_idx = length - n;
        if(remove_idx==0){
            return head->next;
        }
        
        cur = head;
        int idx = 0;
        while(cur!=NULL){
            idx += 1;
            if(idx==remove_idx){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
        
    }
};