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
private:
    bool check(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        else if(root1!=NULL && root2!=NULL)
        {
            if(root1->val==root2->val)
            {
                if(check(root1->left, root2->right) && 
                        check(root1->right, root2->left))
                    return true;
            }
        }
        
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
