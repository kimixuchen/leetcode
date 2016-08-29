/**
Convert Sorted Array to Binary Search Tree
29/08/16 10:13:27
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
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return NULL;
        
        int mid = (left+right)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid-1);
        root->right = build(nums, mid+1, right);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return build(nums, 0, nums.size()-1);
        
    }
};
