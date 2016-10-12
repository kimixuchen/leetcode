/**
LeetCode-235-Lowest Common Ancestor of a Binary Search Tree
12/10/16 09:51:48
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val>=p->val && root->val<=q->val) || 
                    (root->val>=q->val && root->val<=p->val))
            return root;
        
        if(root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        
        return lowestCommonAncestor(root->left, p, q);
        
    }
};
