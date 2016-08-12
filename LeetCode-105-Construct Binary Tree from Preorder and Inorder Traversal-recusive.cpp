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
private:
    map<int,int> inmap;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prepos,
            int inbegin, int inend)
    {
        if(inend < inbegin)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prepos]);
        int inorderRootPos = inmap[root->val];
        
        root->left = build(preorder, inorder, prepos+1, inbegin, inorderRootPos-1);
        root->right = build(preorder, inorder, prepos+inorderRootPos-inbegin+1, 
                inorderRootPos+1, inend);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); ++i)
        {
            inmap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, 0, inorder.size()-1);
    }
};
