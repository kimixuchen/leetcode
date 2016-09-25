/**
LeetCode-404-Sum of Left Leaves
25/09/16 09:37:27
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    int search(TreeNode* root, bool isLeft)
    {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
        {
            return isLeft ? root->val : 0;
        }
        int sum = 0;
        sum += search(root->left, true);
        sum += search(root->right, false);
        
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return search(root, false);
    }
};
