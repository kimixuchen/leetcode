/*
LeetCode-543-Diameter of Binary Tree
10/04/17 10:12:11
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

struct retType{
    int height;
    int diameter;
    retType(int h, int d)
    {
        height = h;
        diameter = d;
    }
};

class Solution {
private:
    retType search(TreeNode* root)
    {
        if(root==NULL)
            return retType(0, 0);
        
        retType retl = search(root->left);
        retType retr = search(root->right);
        
        int height = 1+max(retl.height, retr.height);
        int diameter = max(1+retl.height+retr.height, max(retl.diameter, 
                    retr.diameter));
        
        return retType(height, diameter);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        retType ret = search(root);
        
        return ret.diameter-1;
    }
};
