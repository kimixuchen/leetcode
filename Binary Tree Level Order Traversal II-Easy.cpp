/**
Binary Tree Level Order Traversal II
29/08/16 09:30:18
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<vector<int>> reverseret;
        queue<TreeNode*> q;
        
        if(root==NULL)
            return ret;
        
        q.push(root);
        int count = 1;
        int level = 1;
        while(!q.empty())
        {
            vector<int> levelret;
            TreeNode* curNode;
            int curcount = count;
            count = 0;
            for(int i=0; i<curcount; ++i)
            {
                curNode = q.front();
                q.pop();
                levelret.push_back(curNode->val);
                if(curNode->left!=NULL)
                {
                    ++count;
                    q.push(curNode->left);
                }
                if(curNode->right!=NULL)
                {
                    ++count;
                    q.push(curNode->right);
                }
            }
            ret.push_back(levelret);
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};
