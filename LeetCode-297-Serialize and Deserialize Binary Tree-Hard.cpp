/*
LeetCode-297-Serialize and Deserialize Binary Tree
21/10/16 09:34:11
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(root==NULL)
            return "[]";
        
        vector<string> nums;
        queue<TreeNode*> q;
        q.push(root);
        bool isfirst = true;
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur==NULL)
            {
                nums.push_back("null");
            }
            else
            {
                nums.push_back(to_string(cur->val));
                q.push(cur->left);
                q.push(cur->right);
            }
            
        }
        for(string s = nums.back(); s=="null"; nums.pop_back(), s=nums.back());
        ret = "[";
        for(int i=0; i<nums.size(); ++i)
        {
            if(i==0)
                ret += nums[i];
            else
                ret += ','+nums[i];
        }
        ret += "]";
        //cout<<ret<<endl;
        return ret;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = data.substr(1, data.length()-2);
        if(s == "")
            return NULL;
        stringstream ss(s);
        string num;
        vector<string> nums;
        
        while(getline(ss, num, ','))
        {
            nums.push_back(num);
        }
        
        TreeNode *root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> q;
        q.push(root);
        int pos = 1;
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(pos >= nums.size())
                break;
            string leftnum = nums[pos++];
            string rightnum = "null";
            if(pos < nums.size())
            {
                rightnum = nums[pos++];
            }
                
            //cout<<leftnum<<endl;
            //cout<<rightnum<<endl;
            if(leftnum != "null")
            {
                TreeNode *left = new TreeNode(stoi(leftnum));
                cur->left = left;
                q.push(left);
            }
            else
                cur->left = NULL;
            
            if(rightnum != "null")
            {
                TreeNode *right = new TreeNode(stoi(rightnum));
                cur->right = right;
                q.push(right);
            }
            else
                cur->right = NULL;
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
