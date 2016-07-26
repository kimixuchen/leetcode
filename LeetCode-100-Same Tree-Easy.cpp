/**
LeetCode-100-Same Tree
26/07/16 09:12:53
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
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL && q!=NULL)
        {
            if(p->val == q->val)
            {
                if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
                    return true;
            }
        }
        else if(p==NULL && q==NULL)
        {
            return true;
        }
        
        return false;
    }
};
