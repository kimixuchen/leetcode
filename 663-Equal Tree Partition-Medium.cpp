/*
 * Leetcode 663-Equal Tree Partition
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
    int preorder(TreeNode* root, unordered_map<TreeNode*, int> &sums) {
        if(root == NULL)
            return 0;
        int sum1 = preorder(root->left, sums);
        int sum2 = preorder(root->right, sums);
        sums[root] = root->val + sum1 + sum2;
        
        return sums[root];
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<TreeNode*, int> sums;
        int sum = preorder(root, sums);
        
        if(sums.size()<=1)
            return false;
        bool ret = false;
        for(auto a = sums.begin(); a != sums.end(); a++) {
            if(2*(a->second) == sum) {
                ret = true;
                break;
            }
        }
        
        
        return ret;
    }
};














