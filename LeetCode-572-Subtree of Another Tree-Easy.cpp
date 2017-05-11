/*
LeetCode-572-Subtree of Another Tree
11/05/17 10:45:36
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
class Solution {
private:
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s==NULL && t==NULL)
            return true;
        if(s==NULL || t==NULL)
            return false;
        if(s->val != t->val)
            return false;
        
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)
            return false;
        if(isSame(s, t))
            return true;
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
