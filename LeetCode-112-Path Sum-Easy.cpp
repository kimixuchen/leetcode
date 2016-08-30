/**
LeetCode-112-Path Sum
30/08/16 09:39:43
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

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL)
            return sum == root->val;
        
        sum -= root->val;
        bool hasleft=false, hasright=false;
        if(root->left!=NULL)
            hasleft = hasPathSum(root->left, sum);
        if(root->right!=NULL)
            hasright = hasPathSum(root->right, sum);
        
        return hasleft || hasright;
    }
};
