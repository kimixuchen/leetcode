/**
LeetCode-144-Binary Tree Preorder Traversal
13/09/16 08:45:13
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        if(root==NULL)
            return ret;
        
        s.push(root);
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        
        return ret;
        
    }
};
