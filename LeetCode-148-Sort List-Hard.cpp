/**
LeetCode-148-Sort List
14/09/16 14:48:33
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
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
private:
    ListNode* merge(ListNode *h1, ListNode *h2)
    {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *cur = dummy;
        
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val <= h2->val)
            {
                cur->next = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        if(h2!=NULL)
            h1 = h2;
        
        cur->next = h1;
        
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *p1=head, *p2=head->next;
        
        while(p2!=NULL && p2->next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode *h1=head, *h2=p1->next;
        p1->next = NULL;
        
        h1 = sortList(h1);
        h2 = sortList(h2);
        
        head = merge(h1, h2);
        
        return head;
        
    }
};
