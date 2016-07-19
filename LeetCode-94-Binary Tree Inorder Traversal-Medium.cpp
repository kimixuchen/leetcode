/**
LeetCode-94-Binary Tree Inorder Traversal
19/07/16 09:04:08
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
    void traversal(vector<int> &ret, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        traversal(ret, root->left);
        ret.push_back(root->val);
        traversal(ret, root->right);
        
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        traversal(ret, root);
        
        return ret;
    }
};
