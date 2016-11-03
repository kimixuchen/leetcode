/*
LeetCode-328-Odd Even Linked List
03/11/16 09:54:37
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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL)
            return head;
        
        ListNode *oddp=head, *evenp=head->next;
        ListNode *nextoddp, *nextevenp;
        while(evenp!=NULL && evenp->next!=NULL)
        {
            nextoddp = evenp->next;
            nextevenp = nextoddp->next;
            nextoddp->next = oddp->next;
            oddp->next = nextoddp;
            evenp->next = nextevenp;
            oddp = oddp->next;
            evenp = evenp->next;
        }
        return head;
        
    }
};
