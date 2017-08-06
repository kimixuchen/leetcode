/*
 * Leetcode 654-Maximum Binary Tree
 */
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
    TreeNode* build(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        
        int _max = INT_MIN;
        int maxPos = -1;
        
        for(int i=start; i<=end; i++) {
            if(nums[i] > _max) {
                _max = nums[i];
                maxPos = i;
            }
        }
        
        TreeNode* root = new TreeNode(_max);
        root->left = build(nums, start, maxPos-1);
        root->right = build(nums, maxPos+1, end);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = build(nums, 0, nums.size()-1);
        
        return root;
    }
};









