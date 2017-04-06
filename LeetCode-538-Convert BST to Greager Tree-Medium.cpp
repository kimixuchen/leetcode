/*
LeetCode-538-Convert BST to Greager Tree
06/04/17 10:36:26
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

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

    int update(TreeNode *root, int presum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int sum = root->val;
        sum += update(root->right, presum);
        if(root->right==NULL)
            root->val = root->val + presum;
        else
            root->val = sum + presum;
        presum = root->val;
        sum += update(root->left, presum);
        
        return sum;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        update(root, 0);
        
        return root;
    }
};
