/**
LeetCode-117-Populating Next Right Pointers in Each Node II
31/08/16 10:19:24
xuchen
**/

#include <iostream>
#include <cfloat>
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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* preNode = root;
        while(preNode!=NULL)
        {
            TreeLinkNode *cur=preNode, *lfirst=NULL, *lp=NULL;
            while(cur != NULL)
            {
                TreeLinkNode *firstchild = NULL;
                TreeLinkNode *secondchild = NULL;
                if(cur->left!=NULL && cur->right!=NULL)
                {
                    cur->left->next = cur->right;
                    firstchild = cur->left;
                    secondchild = cur->right;
                }
                else
                {
                    if(cur->left!=NULL)
                        firstchild = cur->left;
                    else if(cur->right!=NULL)
                        firstchild = cur->right;
                }
                
                if(firstchild!=NULL)
                {
                    if(lfirst==NULL)
                        lfirst = firstchild;
                    
                    if(lp!=NULL)
                    {
                        lp->next = firstchild;
                    }
                    
                    if(secondchild!=NULL)
                    {
                        lp = secondchild;
                    }
                    else
                    {
                        lp = firstchild;
                    }
                }
                cur = cur->next;
            }
            preNode = lfirst;
        }
        
        return;
    }
};
