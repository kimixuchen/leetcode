/*
LeetCode-508-Most Frequent Subtree Sum
07/02/17 09:05:53
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
    int search(TreeNode* root, unordered_map<int, int>& frequence, int& most)
    {
        if(root==NULL)
            return 0;
        
        int leftsum = search(root->left, frequence, most);
        int rightsum = search(root->right, frequence, most);
        
        int sum = root->val + leftsum + rightsum;
        
        frequence[sum]++;
        if(frequence[sum]>most)
            most = frequence[sum];
        
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> frequence;
        int most = 0;
        
        search(root, frequence, most);
        
        vector<int> ret;
        for(auto it = frequence.begin(); it!=frequence.end(); ++it)
        {
            if(it->second == most)
                ret.push_back(it->first);
        }
        
        return ret;
    }
};
