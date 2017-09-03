/**
LeetCode-671-Second Minimum Node In a Binary Tree
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
 private:
	vector<int> num;
	int _min;
	void search(TreeNode* root) {
		if(root == NULL)
			return;
		if(root->val != _min) {
			num.push_back(root->val);
			return;
		}
		search(root->left);
		search(root->right);
	}
public:
    int findSecondMinimumValue(TreeNode* root) {
		_min = root->val;
		num.push_back(_min);
		search(root);
		sort(num.begin(), num.end());
		
		if(num.size() > 1) {
			return num[1];
		}
		else {
			return -1;
		}
    }
};












