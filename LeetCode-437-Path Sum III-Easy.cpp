/*
LeetCode-437-Path Sum III
02/12/16 10:45:22
xuchen
**/

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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

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
    int search(TreeNode* root, int cursum, int target, unordered_map<int, int>
            &prefixMap)
    {
        if(root==NULL)
            return 0;
        
        int res = 0;
        cursum += root->val;
        if(prefixMap.find(cursum-target) != prefixMap.end())
        {
            res = prefixMap[cursum-target];
        }
        
        if(prefixMap.find(cursum)!=prefixMap.end())
            prefixMap[cursum]++;
        else
            prefixMap[cursum] = 1;
        
        res += search(root->left, cursum, target, prefixMap) + 
            search(root->right, cursum, target, prefixMap);
        
        prefixMap[cursum]--;
        
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        
        return search(root, 0, sum, prefixMap);
    }
};
