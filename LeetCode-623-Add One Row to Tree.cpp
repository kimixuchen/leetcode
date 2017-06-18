/**
LeetCode-623-Add One Row to Tree
2017-06-18 09:58:51
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
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

private: 
void preorder(TreeNode* root, int curDepth, int targetDepth, int v) {
    if(root == NULL)
        return;
    
    if(curDepth == targetDepth) {
        TreeNode *newleft = new TreeNode(v);
        newleft->left = root->left;
        TreeNode *newright = new TreeNode(v);
        newright->right = root->right;
        root->left = newleft;
        root->right = newright;
        
        return;
    }

    preorder(root->left, curDepth+1, targetDepth, v);
    preorder(root->right, curDepth+1, targetDepth, v);

    return;
}
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1) {
            TreeNode *newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }

        preorder(root, 1, d-1, v);

        return root;
    }
};