/**
LeetCode-105-Construct Binary Tree from Preorder and Inorder Traversal
12/08/16 07:38:24
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> ts;
        int preorderPos=0, inorderPos=0;
        bool flag = false;
        if(preorder.size() == 0)
            return NULL;
        
        TreeNode* t = new TreeNode(preorder[0]);
        TreeNode* root = t;
        ts.push(root);
        preorderPos++;
        
        while(preorderPos < preorder.size())
        {
            if(!ts.empty() && ts.top()->val==inorder[inorderPos])
            {
                flag = true;
                t = ts.top();
                ts.pop();
                inorderPos++;
            }
            else
            {
                if(!flag)
                {
                    t->left = new TreeNode(preorder[preorderPos]);
                    t = t->left;
                    ts.push(t);
                    preorderPos++;
                }
                else
                {
                    flag = false;
                    t->right = new TreeNode(preorder[preorderPos]);
                    t = t->right;
                    ts.push(t);
                    preorderPos++;
                }
            }
        }
        
        return root;
    }
};
