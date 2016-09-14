/**
LeetCode-147-Insertion Sort List
14/09/16 14:09:13
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
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next!=NULL)
        {
            ListNode* cur = pre->next;
            bool insert = false;
            for(ListNode* p=dummy; p!=cur; p=p->next)
            {
                if(p->next->val > cur->val)
                {
                    pre->next = cur->next;
                    cur->next = p->next;
                    p->next = cur;
                    insert = true;
                    break;
                }
            }
            if(!insert)
                pre = pre->next;
        }
        
        head = dummy->next;
        free(dummy);
        return head;
        
    }
};
