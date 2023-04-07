/*
160. Intersection of Two Linked Lists (https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

ex:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

Hint: listA + listB = listB + listA
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { // one run, len(a+c+b) == len(b+c+a)
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        while(cur1!=cur2){ // if not intersect? both reach NULL after a+b(or b+a)
            cur1 = cur1==NULL? headB: cur1->next;
            cur2 = cur2==NULL? headA: cur2->next;
        }
        return cur1;
    }

    ListNode *getIntersectionNode_v2(ListNode *headA, ListNode *headB) { //using map, but still not using O(1) space, also find in map cost extra time
        unordered_map<ListNode*, int> myMap;

        ListNode* cur = headA;
        while(cur!=NULL){
            myMap[cur] = 1;
            cur = cur->next;
        }

        cur = headB;
        while(cur!=NULL){
            if(myMap.find(cur)!=myMap.end()){
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode_v1(ListNode *headA, ListNode *headB) { // not using O(1) space
        vector<ListNode*> v1;
        vector<ListNode*> v2;

        ListNode* cur = headA;
        while(cur!=NULL){
            v1.push_back(cur);
            cur = cur->next;
        }

        cur = headB;
        while(cur!=NULL){
            v2.push_back(cur);
            cur = cur->next;
        }

        int length = min(v1.size(), v2.size());
        for(int i=0; i<length; i++){
            if(v1[v1.size()-1-i]!=v2[v2.size()-1-i]){
                if(i==0){
                    return NULL;
                }else{
                    return v1[v1.size()-i];
                }
            }
        }

        if(v1.size()>v2.size()){
            return v2[0];
        }else{
            return v1[0];
        }
    }
};