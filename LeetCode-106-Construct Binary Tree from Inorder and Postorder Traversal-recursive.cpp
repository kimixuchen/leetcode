/**
LeetCode-106-Construct Binary Tree from Inorder and Postorder Traversal
28/08/16 09:36:38
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
    map<int,int> inorderPos;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in1, int in2,
            int post1, int post2)
    {
        if(post1 > post2)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[post2]);
        int mid = inorderPos[postorder[post2]];
        root->left = build(inorder, postorder, in1, mid-1, post1, post1+mid-in1-1);
        root->right = build(inorder, postorder, mid+1, in2, post1+mid-in1, post2-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); ++i)
            inorderPos[inorder[i]] = i;
        
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        
    }
};
