/**
LeetCode-129-Sum Root to Leaf Numbers
07/09/16 08:31:32
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
    void dfs(TreeNode* root, int presum, int& sum)
    {
        presum *= 10;
        presum += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum += presum;
            return;
        }
        if(root->left != NULL)
            dfs(root->left, presum, sum);
        if(root->right != NULL)
            dfs(root->right, presum, sum);
        
        return;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(root != NULL)
            dfs(root, 0, sum);
        
        return sum;
    }
};
