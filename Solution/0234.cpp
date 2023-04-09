/*
234. Palindrome Linked List (https://leetcode.com/problems/palindrome-linked-list/description/)

Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

ex:
Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

Could you do it in O(n) time and O(1) space?
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

    bool compare(ListNode* head, ListNode* &x){
        if(head!=NULL){
            bool ans = compare(head->next, x);
            if(head->val==x->val){
                x = x->next;
                return ans&&true;
            }
            else{
                x = x->next;
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) { // similar idea, using the idea of recursion
        return compare(head, head);
    }

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* cur = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
    bool isPalindrome_v1(ListNode* head) { // naive idea, O(n) time and O(1) space, but break the original linked list (need extra steps to restore it back)

        // count length
        int length = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            length += 1;
            cur = cur->next;
        }

        if(length==1){
            return true;
        }

        int mid = length/2;
        cur = head;
        ListNode* head2;
        for(int i=0; i<mid; i++){
            if(i==mid-1){
                head2 = cur->next;
                cur->next = NULL;
                break;
            }
            cur = cur->next;
        }
        head2 = reverse(head2); //reverse the latter half


        // compare the first half and the reversed second half
        ListNode* cur2 = head2;
        cur = head;
        for(int i=0; i<mid; i++){
            if(cur->val!=cur2->val){
                return false;
            }
            cur = cur->next;
            cur2 = cur2->next;
        }
        return true;
    }
};