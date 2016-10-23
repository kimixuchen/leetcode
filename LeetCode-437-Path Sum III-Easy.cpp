/*
LeetCode-437-Path Sum III
23/10/16 09:44:04
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
    
    void getNFromRoot(TreeNode* root, int sum, int cursum, int &counter)
    {
        if(root==NULL)
            return;
        
        cursum += root->val;
        if(cursum==sum)
            ++counter;
        
        getNFromRoot(root->left, sum, cursum, counter);
        getNFromRoot(root->right, sum, cursum, counter);
    }
    
    int dfs(TreeNode* root, int sum)
    {
        if(root==NULL)
            return 0;
        
        int counter = 0;
        getNFromRoot(root, sum, 0, counter);
        
        counter += dfs(root->left, sum);
        counter += dfs(root->right, sum);
        
        return counter;
    }

public:
    int pathSum(TreeNode* root, int sum) {
        
        return dfs(root, sum);
        
    }
};
