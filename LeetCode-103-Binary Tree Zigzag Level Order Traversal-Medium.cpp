/**
LeetCode-103-Binary Tree Zigzag Level Order Traversal
29/07/16 17:08:11
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
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
    void upsidedown(vector<int> &oneTravel)
    {
        int i=0, j=oneTravel.size()-1;
        int tmp;
        while(i<j)
        {
            tmp = oneTravel[i];
            oneTravel[i] = oneTravel[j];
            oneTravel[j] = tmp;
            ++i;
            --j;
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> oneTravel;
        queue<TreeNode*> q;
        int count = 1;
        q.push(root);
        
        int cur = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ++cur;
            if(node!=NULL)
            {
                oneTravel.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(cur == count)
            {
                if(oneTravel.size()!=0)
                    ret.push_back(oneTravel);
                oneTravel.clear();
                count = q.size();
                cur = 0;
            }
        }
        
        for(int i=0; i<ret.size(); ++i)
        {
            if(i%2 == 1)
            {
                upsidedown(ret[i]);
            }
        }
        return ret;
    }
};
