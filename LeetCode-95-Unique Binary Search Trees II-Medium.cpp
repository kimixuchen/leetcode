/**
LeetCode-95-Unique Binary Search Trees II
19/07/16 09:26:23
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    vector<TreeNode*> search(int start, int end)
    {
        vector<TreeNode*> ret;
        if(start > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i=start; i<=end; ++i)
        {
            vector<TreeNode*> leftTrees = search(start, i-1);
            vector<TreeNode*> rightTrees = search(i+1, end);
            
            for(auto leftTree : leftTrees)
            {
                for(auto rightTree : rightTrees)
                {
                    TreeNode* newroot = new TreeNode(i);
                    newroot->left = leftTree;
                    newroot->right = rightTree;
                    ret.push_back(newroot);
                }
            }
        }
        
        return ret;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0)
            return vector<TreeNode*>();
        
        return search(1, n);  
    }
};
