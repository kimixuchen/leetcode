/**
LeetCode-92-Reverse Linked List II
18/07/16 09:25:43
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dumy = new ListNode(0);
        dumy->next = head;
        ListNode *before, *begin;
        ListNode *pre;
        ListNode* cur = dumy;
        for(int i=0; i<m-1; ++i)
        {
            cur = cur->next;
        }
        before = pre = cur;
        cur = cur->next;
        begin = cur;
        for(int i=m-1; i<n; ++i)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        before->next = pre;
        begin->next = cur;
        
        return dumy->next;
    }
};
