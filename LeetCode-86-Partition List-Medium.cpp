/**
LeetCode-86-Partition List
15/07/16 08:34:42
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dumy = new ListNode(0);
        dumy->next = head;
        ListNode* pre = dumy;
        ListNode* cur = dumy;
        while(cur->next != NULL)
        {
            if(cur->next->val < x)
            {
                if(pre != cur)
                {
                    ListNode* tmp = cur->next;
                    cur->next = tmp->next;
                    tmp->next = pre->next;
                    pre->next = tmp;
                }
                else
                {
                    cur = cur->next;
                }
                pre = pre->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        return dumy->next;
    }
};
