/*
LeetCode-337-House Robber III
14/11/16 10:18:57
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
    int search(TreeNode *root, bool rob, unordered_map<TreeNode*, int> &robmax,
            unordered_map<TreeNode*, int> &norobmax)
    {
        if(root==NULL)
            return 0;
        
        if(rob && robmax.find(root) != robmax.end())
            return robmax[root];
        if(!rob && norobmax.find(root) != norobmax.end())
            return norobmax[root];
        
        int sum = 0;
        if(rob)
        {
            sum += root->val;
            sum += search(root->left, false, robmax, norobmax);
            sum += search(root->right, false, robmax, norobmax);
        }
        else
        {
            sum += max(search(root->left, false, robmax, norobmax), 
                    search(root->left, true, robmax, norobmax));
            sum += max(search(root->right, false, robmax, norobmax), 
                    search(root->right, true, robmax, norobmax));
        }
        if(rob)
            robmax[root] = sum;
        else
            norobmax[root] = sum;
        
        return sum;
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> robmax;
        unordered_map<TreeNode*, int> norobmax;
        int sum = 0;
        sum = max(search(root, false, robmax, norobmax), 
                search(root, true, robmax, norobmax));
        
        return sum;
    }
};
