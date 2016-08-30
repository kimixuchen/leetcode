/**
LeetCode-114-Flatten Binary Tree to Linked List
30/08/16 10:24:41
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    
    TreeNode* sharp(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        
        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;
        TreeNode* lLeaf = sharp(lchild);
        TreeNode* rLeaf = sharp(rchild);
        if(lchild != NULL)
        {
            root->right = lchild;
            lLeaf->right = rchild;
        }
        else
        {
            root->right = rchild;
        }
        root->left = NULL;
        
        if(rLeaf == NULL)
        {
            if(lLeaf==NULL)
                return root;
            else
                return lLeaf;
        }
        else
            return rLeaf;
    }

public:
    void flatten(TreeNode* root) {
        sharp(root);
    }
};
