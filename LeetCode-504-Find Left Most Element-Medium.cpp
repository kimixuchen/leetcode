/*
LeetCode-504-Find Left Most Element
12/02/17 10:45:15
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
    int leftLevel = 0, leftnum = -1;
    
    void dfs(TreeNode* root, int curLevel)
    {
        if(root==NULL)
            return;
        
        if(curLevel > leftLevel)
        {
            leftLevel = curLevel;
            leftnum = root->val;
        }
        dfs(root->left, curLevel+1);
        dfs(root->right, curLevel+1);
    
    }
public:
    int findLeftMostNode(TreeNode* root) {
        dfs(root, 1);
        
        return leftnum;
    }
};
