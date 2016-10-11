/**
LeetCode-230-Kth Smallest Element in a BST
11/10/16 20:53:33
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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int id=0;
        int ans;
        
        s.push(root);
        while(!s.empty())
        {
            if(cur!=s.top())
            {
                ++id;
                if(id==k)
                {
                    ans = s.top()->val;
                    break;
                }
                cur = s.top()->right;
                s.pop();
                    
            }
            else
            {
                cur = cur->left;
            }
            if(cur!=NULL)
                s.push(cur);
        }
        return ans;
        
    }
};
