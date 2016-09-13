/**
LeetCode-145-Binary Tree Preorder Traversal II
13/09/16 08:54:29
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
private:
    bool isLeaf(TreeNode* root)
    {
        if(root==NULL)
            return true;
        
        return root->left==NULL && root->right==NULL;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        TreeNode* cur;
        cur = root;
        
        while(!s.empty() || cur!=NULL)
        {
            while(!isLeaf(cur))
            {
                s.push(cur);
                cur = cur->left;
            }
            
            if(cur!=NULL)
                ret.push_back(cur->val);
            
            while(!s.empty() && cur==s.top()->right)
            {
                cur = s.top();
                s.pop();
                ret.push_back(cur->val);
            }
            
            if(s.empty())
                cur = NULL;
            else
                cur = s.top()->right;
        }
        
        return ret;
        
    }
};
