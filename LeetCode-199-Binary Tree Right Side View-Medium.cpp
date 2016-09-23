/**
LeetCode-199-Binary Tree Right Side View
23/09/16 08:22:21
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while(!q.empty())
        {
            n = q.size();
            TreeNode* cur;
            for(int i=0; i<n; ++i)
            {
                cur = q.front();
                q.pop();
                if(i==n-1)
                    ret.push_back(cur->val);
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
        }
        return ret;
        
    }
};
