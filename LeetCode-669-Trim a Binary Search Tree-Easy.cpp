/**
LeetCode-669-Trim a Binary Search Tree
2017年9月3日
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include <set>
#include <sstream>
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
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		if(root == NULL)
			return NULL;
		
		if(root->val >= L && root->val <= R) {
			root->left = trimBST(root->left, L, R);
			root->right = trimBST(root->right, L, R);
		}
		else if(root->val < L) {
			root = trimBST(root->right, L, R);
		}
		else if(root->val > R) {
			root = trimBST(root->left, L, R);
		}

		return root;
    }
};












