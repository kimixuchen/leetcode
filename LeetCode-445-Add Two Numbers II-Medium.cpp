/*
LeetCode-445-Add Two Numbers II
12/01/17 09:47:50
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

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
    int getLength(ListNode *h)
    {
        int len = 0;
        while(h!=NULL)
        {
            ++len;
            h = h->next;
        }
        return len;
    }
    
    ListNode* add(ListNode *h1, int len1, ListNode *h2, int len2)
    {
        if(len1==1 && len2==1)
        {
            h1->val += h2->val;
            return h1;
        }
        
        if(len1>len2)
        {
            ListNode *after = add(h1->next, len1-1, h2, len2);
            int inc = 0;
            if(after->val > 9)
            {
                inc = 1;
                after->val = (after->val)%10;
            }
            h1->val += inc;
        }
        else
        {
            ListNode *after = add(h1->next, len1-1, h2->next, len2-1);
            int inc = 0;
            if(after->val > 9)
            {
                inc = 1;
                after->val = (after->val)%10;
            }
            h1->val += (h2->val+inc);
        }
        
        return h1;
    
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        if(len1 < len2)
        {
            h1 = l2;
            h2 = l1;
            swap(len1, len2);
        }
        
        ListNode *head = add(h1, len1, h2, len2);
        ListNode *ret = head;
        if(head->val > 9)
        {
            ret = new ListNode(1);
            head->val = head->val % 10;
            ret->next = head;
        }
        
        return ret;
    }
};
