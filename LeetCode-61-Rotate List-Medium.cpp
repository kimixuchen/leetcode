/**
LeetCode-60-Rotate List
06/07/16 19:29:18
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode *cur = head;
        ListNode *preKNode = head;
        int count = 0;
        while(count < k)
        {
            while(count<k && cur->next!=NULL)
            {
                cur = cur->next;
                ++count;
            }
            if(count+1 <= k)
            {
                k %= (count+1);
                count = 0;
                cur = head;
            }
        }
        
        while(cur->next!=NULL)
        {
            cur = cur->next;
            preKNode = preKNode->next;
        }
        cur->next = head;
        ListNode *newHead = preKNode->next;
        preKNode->next = NULL;
        
        return newHead;
    }
};
