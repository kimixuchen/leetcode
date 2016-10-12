/**
LeetCode-234-Palindrome Linked List
12/10/16 09:07:30
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
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
    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode *cur = head, *p = head->next;
        
        while(p!=NULL)
        {
            ListNode *t = p->next;
            p->next = cur;
            cur = p;
            p = t;
        }
        head->next = NULL;
        return cur;
    }
public:
    bool isPalindrome(ListNode* head) {
        bool ret = false;
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head2=reverseLinkedList(slow);
        ListNode *p1=head, *p2=head2;
        while(p1 != NULL)
        {
            if(p1->val!=p2->val)
                break;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==NULL)
            ret = true;
        
        reverseLinkedList(head2);
        
        return ret;
    }
};
