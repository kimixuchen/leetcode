/**
LeetCode-141-Linked List Cycle
10/09/16 12:06:53
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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *fast, *slow;
        slow = head;
        fast = head->next;
        
        while(fast!=NULL && slow!=NULL)
        {
            slow = slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
            else
                fast = fast->next;
            
            if(slow==fast)
                return true;
        }
        
        return false;
        
    }
};
