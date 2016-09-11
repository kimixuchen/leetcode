/**
LeetCode-138-Copy List with Random Pointer
11/09/16 09:21:41
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
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> nodes;
        RandomListNode *root;
        RandomListNode *cur;
        RandomListNode *curNew;
        root = new RandomListNode(head->label);
        RandomListNode *pre = root;
        cur = head->next;
        nodes[head] = root;
        
        while(cur != NULL)
        {
            curNew = new RandomListNode(cur->label);
            nodes[cur] = curNew;
            pre->next = curNew;
            pre = curNew;
            cur = cur->next;
        }
        
        curNew = root;
        cur = head;
        while(cur != NULL)
        {
            curNew->random = nodes[cur->random];
            cur = cur->next;
            curNew = curNew->next;
        }
        
        return root;
        
    }
};
