/*
 * Leetcode 655-Print Binary Tree
 */
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
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        int hl = getHeight(root->left);
        int hr = getHeight(root->right);
        
        return max(hl, hr) + 1;
    }
    
    void preorder(TreeNode *root, int offset, int level, int h, 
        vector<vector<string>> &res) {
        if (level >= h || root == NULL)
            return;
        
        res[level][offset] = to_string(root->val);
        
        level++;
        preorder(root->left, offset - 1 - ((int)pow(2, (h-level-1))-1), level, h, res);
        preorder(root->right, offset + 1 + (int)pow(2, (h-level-1))-1, level, h, res);
        
        return;
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        vector<vector<string>> res(h, vector<string>((int)pow(2, h)-1));
        
        preorder(root, (int)pow(2, h-1)-1, 0, h, res);
        
        return res;
        
    }
};








