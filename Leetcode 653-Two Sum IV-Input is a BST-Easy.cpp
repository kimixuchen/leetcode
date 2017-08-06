/*
 * Leetcode 653-Two Sum IV-Input is a BST
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
    void inorder(TreeNode* root, vector<int> &a)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
        
        return;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root, a);
        
        int n = a.size();
        if(n<2)
            return false;
        int pos1 = 0, pos2 = n - 1;
        
        while(pos1<pos2)
        {
            if(a[pos1] + a[pos2] < k) {
                pos1++;
            }
            else if(a[pos1] + a[pos2] > k) {
                pos2--;
            }
            else {
                break;
            }
        }
        
        if(pos1 < pos2)
            return true;
        else
            return false;
    }
};










