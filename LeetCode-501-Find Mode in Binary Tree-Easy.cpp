/**
LeetCode-501-Find Mode in Binary Tree
2017-01-30 09:25:47
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include <set>
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
	void search(TreeNode* root, unordered_map<int, int> &valtimes, int &maxtimes)
	{
		if(root==NULL)
			return;
		
		valtimes[root->val]++;
		if(valtimes[root->val]>maxtimes)
			maxtimes = valtimes[root->val];
		search(root->left, valtimes, maxtimes);
		search(root->right, valtimes, maxtimes);

		return;
	}

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> valtimes;
        int maxtimes = 0;
        search(root, valtimes, maxtimes);

        vector<int> ret;
        for(auto it = valtimes.begin(); it!=valtimes.end(); ++it)
        {
        	if(it->second == maxtimes)
        		ret.push_back(it->first);
        }

        return ret;
    }
};