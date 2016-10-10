/**
LeetCode-222-Count Complete Tree Nodes
10/10/16 08:07:35
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
private:
    int search(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int ret = 0;
        int lh = getLeftHeight(root->left);
        int rh = getRightHeight(root->right);
        if(lh==rh)
        {
            ret = pow(2, lh+1)-1;
        }
        else if(lh > rh)
        {
            ret += search(root->left);
            ret += search(root->right);
            ret += 1;
        }
        
        return ret;
    }
    
    int getRightHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        TreeNode *cur = root;
        int h = 0;
        while(cur != NULL)
        {
            h++;
            cur = cur->right;
        }
        return h;
    }
    int getLeftHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        TreeNode *cur = root;
        int h = 0;
        while(cur != NULL)
        {
            h++;
            cur = cur->left;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        return search(root);
    }
};
