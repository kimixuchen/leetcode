/**
LeetCode-124-Binary Tree Maxium Path Sum
01/09/16 10:23:05
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
private:
    int maxSum;
    int getMax(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int lMax = max(0, getMax(root->left));
        int rMax = max(0, getMax(root->right));
        int maxchild = max(lMax, rMax);
        maxSum = max(maxSum, root->val+lMax+rMax);
        
        return max(lMax+root->val, rMax+root->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        getMax(root);
        
        return maxSum;
    }
};
