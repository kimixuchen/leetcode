/**
LeetCode-110-Balanced Binary Tree
30/08/16 09:02:20
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
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int lchild = depth(root->left);
        if(lchild == -1)
            return -1;
        int rchild = depth(root->right);
        if(rchild == -1)
            return -1;
        
        if(abs(lchild-rchild) > 1)
            return -1;
        else
            return 1 + max(lchild, rchild);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};
