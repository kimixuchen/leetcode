/**
LeetCode-98-Validate Binary Search Tree
20/07/16 16:38:42
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
    long long getMinChild(TreeNode* root)
    {
        if(root==NULL)
            return 2147483648;
        while(root->left != NULL)
            root=root->left;
        
        return root->val;
    }

    long long getMaxChild(TreeNode* root)
    {
        if(root==NULL)
            return -2147483649;
        while(root->right != NULL)
            root=root->right;
        
        return root->val;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        
        long long value = root->val;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if(isValidBST(left) && getMaxChild(left)<value && 
            isValidBST(right) && getMinChild(right)>value)
            return true;
        else
            return false;
    }
};
