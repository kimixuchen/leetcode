/**
LeetCode-111-Minimum Depth of Binary Tree
30/08/16 09:29:54
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = minDepth(root->left);
        if(lh == 1)
            return 1 + lh;
        
        int rh = minDepth(root->right);
        
        if(min(lh, rh) == 0)
            return 1 + max(lh, rh);
        else
            return 1 + min(lh, rh);
    }
};
