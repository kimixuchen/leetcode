/**
LeetCode-116-Populating Next Right Pointers in Each Node
31/08/16 09:38:12
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
        while(root!=NULL && root->left!=NULL && root->right!=NULL)
        {
            TreeLinkNode* cur = root;
            while(cur != NULL)
            {
                cur->left->next = cur->right;
                if(cur->next!=NULL)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            root = root->left;
        }
        
        return;
    }
};
