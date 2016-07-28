/**
LeetCode-101-Symmetric Tree
28/07/16 15:35:32
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
    bool isSymmetric(TreeNode* root) {
        TreeNode *a, *b;
        if(root == NULL)
            return true;
        a = root->left;
        b = root->right;
        queue<TreeNode*> q;
        q.push(a);
        q.push(b);

        while(!q.empty())
        {
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            if(a==NULL && b==NULL)
                continue;
            if((a==NULL ^ b==NULL) == 1)
                return false;
            if(a->val != b->val)
                return false;
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
        
        return true;
    }
};
