/**
LeetCode-113-Path Sum II
30/08/16 10:11:01
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
    vector<vector<int>> allPaths;
    void dfs(TreeNode* root, int sum, vector<int>& path)
    {
        if(root == NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum == root->val)
            {
                path.push_back(root->val);
                allPaths.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        sum -= root->val;
        path.push_back(root->val);
        dfs(root->left, sum, path);
        dfs(root->right, sum, path);
        path.pop_back();
        
        return;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, sum, path);
        
        return allPaths;
    }
};
