#include <iostream>
#include <alogrithm>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>

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
	int pre;
	int gap;

	void inordor(TreeNode* root){
		if(root==NULL)
			return;

		inordor(root->left);

		if(pre!=-1)
		{
			if(root->val-pre < gap)
			{
				gap = root->val-pre;
			}
		}
		
		pre = root->val;
		inordor(root->right);

		return;
	}

public:
    int getMinimumDifference(TreeNode* root) {
        pre = -1;
        gap = INT_MAX;

        inordor(root);

        return gap;
    }
};