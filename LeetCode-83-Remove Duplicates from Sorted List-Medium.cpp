/**
LeetCode-83-Remove Duplicates from Sorted List
14/07/16 10:21:52
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curNode = head;
        ListNode* preNode = head;
        
        while(curNode != NULL)
        {
            if(curNode->val != preNode->val)
            {
                preNode->next = curNode;
                preNode = curNode;
            }
            
            curNode = curNode->next;
        }
        if(preNode != NULL && preNode->next != NULL)
            preNode->next = NULL;
        
        return head;
    }
};
