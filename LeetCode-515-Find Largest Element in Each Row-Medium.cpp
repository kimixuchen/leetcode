/*
LeetCode-515-Find Largest Element in Each Row
12/02/17 10:58:15
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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
    void dfs(TreeNode* root, int level, vector<int>& maxs)
    {
        if(root==NULL)
            return;
        
        if(maxs.size()<level)
            maxs.push_back(root->val);
        if(maxs[level-1] < root->val)
            maxs[level-1] = root->val;
        
        dfs(root->left, level+1, maxs);
        dfs(root->right, level+1, maxs);
        
        return;
    }
public:
    vector<int> findValueMostElement(TreeNode* root) {
        vector<int> maxs;
        
        if(root == NULL)
            return maxs;
        
        dfs(root, 1, maxs);
        
        return maxs;
    }
};
