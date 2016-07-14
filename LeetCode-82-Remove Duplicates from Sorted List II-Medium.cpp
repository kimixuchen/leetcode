/**
LeetCode-82-Remove Duplicates from Sorted List II
14/07/16 09:41:42
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
        ListNode* newHead = new ListNode(INT_MAX);
        newHead->next = head;
        ListNode* preNode = newHead;
        ListNode* curNode = head;
        int preNum = INT_MAX;
        int counter = 0;
        
        while(curNode != NULL)
        {
            if(curNode == head)
            {
                preNum = head->val;
                counter = 1;
            }
            else
            {
                if(curNode->val == preNum)
                {
                    ++counter;
                }
                else
                {
                    if(counter == 1)
                    {
                        preNode = preNode->next;
                    }
                    else
                    {
                        preNode->next = curNode;
                    }
                    counter = 1;
                    preNum = curNode->val;
                }
            }
            curNode = curNode->next;
        }
        if(counter > 1)
            preNode->next = NULL;
        
        return newHead->next;
    }
};
