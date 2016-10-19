/**
LeetCode-257-Binary Tree Paths
19/10/16 09:15:40
xuchen
**/

#include <iostream>
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
    void search(TreeNode *root, vector<string> &ret, string s)
    {
        if(s!="")
            s += "->";
        s += to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            ret.push_back(s);
            return;
        }
        
        if(root->left != NULL)
            search(root->left, ret, s);
        if(root->right != NULL)
            search(root->right, ret, s);
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root==NULL)
            return ret;
        
        search(root, ret, "");
        
        return ret;
    }
};
