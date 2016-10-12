/**
LeetCode-235-Lowest Common Ancestor of a Binary Tree
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
private:
    int search(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** ret)
    {
        if(root==NULL)
        {
            *ret = NULL;
            return 0;
        }
        TreeNode *r1, *r2;
        int a = search(root->left, p, q, &r1);
        if(a==2)
        {
            *ret = r1; 
            return 2;
        }
        int b = search(root->right, p, q, &r2);
        if(b==2)
        {
            *ret = r2;
            return 2;
        }
        if((a==1&&b==1) || (max(a, b)==1 && (root==p || root==q)))
        {
            *ret = root;
            return 2;
        }
        
        *ret = NULL;
        return max(max(a, b), (root==p||root==q)?1:0);
    
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret;
        search(root, p, q, &ret);
        return ret;
        
    }
};
