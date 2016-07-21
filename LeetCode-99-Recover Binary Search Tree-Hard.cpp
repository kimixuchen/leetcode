/**
LeetCode-99-Recover Binary Search Tree
21/07/16 08:52:18
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
    void recoverTree(TreeNode* root) {
        TreeNode* preNode = new TreeNode(INT_MIN);
        TreeNode* firstNode = NULL;
        TreeNode* secondNode = NULL;
        TreeNode* backupSecondNode = NULL;
        
        TreeNode* cur = root;
        
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                if(firstNode==NULL && cur->val<=preNode->val)
                {
                    firstNode = preNode;
                    backupSecondNode = cur;
                }
                else if(secondNode==NULL && cur->val<=preNode->val)
                {
                    secondNode = cur;
                }
                preNode = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode* pre = cur->left;
                while(pre->right != NULL)
                {
                    if(pre->right == cur)
                        break;
                    pre = pre->right;
                }
                
                if(pre->right == cur)
                {
                    pre->right = NULL;
                    if(firstNode==NULL && cur->val<=preNode->val)
                    {
                        firstNode = preNode;
                        backupSecondNode = cur;
                    }
                    else if(secondNode==NULL && cur->val<=preNode->val)
                    {
                        secondNode = cur;
                    }
                    preNode = cur;
                    cur = cur->right;
                }
                else if(pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
        }
        
        if(secondNode == NULL)
            secondNode = backupSecondNode;
        int tmp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tmp;
        
        return;
    }
};
