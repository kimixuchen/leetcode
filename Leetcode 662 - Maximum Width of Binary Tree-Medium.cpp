/*
 * Leetcode 662 - Maximum Width of Binary Tree
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
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while(!q.empty()) {
            int n = q.size();
            int l = 0;
            int r = 0;
            for(int i=0; i<n; i++) {
                auto item = q.front();
                q.pop();
                if(item.first == NULL) {
                    continue;
                }
                if(i==0)
                    l = item.second;
                if(i==n-1)
                    r = item.second;
                if((item.first)->left) {
                    q.push(make_pair((item.first)->left, 2*(item.second)-1));
                }
                if((item.first)->right) {
                    q.push(make_pair((item.first)->right, 2*(item.second)));
                }
            }
            maxWidth = max(maxWidth, r-l+1);
        }
        
        return maxWidth;
    }
};














