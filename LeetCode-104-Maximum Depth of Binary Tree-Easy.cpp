/**
LeetCode-104-Maximum Depth of Binary Tree
03/08/16 09:57:18
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <set>
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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL)
            return depth;
        
        return 1+max(maxDepth(root->left), maxDepth(root->right));
        
    }
};
